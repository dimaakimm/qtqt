#include "ClientManager.h"

ClientManager::ClientManager(QHostAddress ip, ushort port, QObject *parent)
    : QObject{parent}, _ip(ip), _port(port)
{
    _socket = new QTcpSocket(this);
    connect(_socket, &QTcpSocket::connected, this, &ClientManager::connected);
    connect(_socket, &QTcpSocket::disconnected, this, &ClientManager::disconnected);
    connect(_socket, &QTcpSocket::readyRead, this, &ClientManager::readyRead);

}

ClientManager::ClientManager(QTcpSocket *client, QObject *parent)
    : QObject{parent}, _socket(client)
{
    connect(_socket, &QTcpSocket::connected, this, &ClientManager::connected);
    connect(_socket, &QTcpSocket::disconnected, this, &ClientManager::disconnected);
    connect(_socket, &QTcpSocket::readyRead, this, &ClientManager::readyRead);

}

void ClientManager::connectToServer()
{
    _socket->connectToHost(_ip, _port);
}

void ClientManager::sendMessage(QString message)
{
    _socket->write(_protocol.textMessage(message));
}

void ClientManager::sendErrorRegistration(QString errorMessage)
{
    _socket->write(_protocol.registrationErrorMessage(errorMessage));
}

void ClientManager::sendUsername(QString username)
{
    _socket->write(_protocol.setUsernameMessage(username));
}

void ClientManager::sendPassword(QString password)
{
    _socket->write(_protocol.setPasswordMessage(password));
}

void ClientManager::sendIsTyping()
{
    _socket->write(_protocol.isTypingMessage());
}


QString ClientManager::username() const
{
    auto id = _socket->property("id").toInt();
    auto username = _protocol.username();
    if (username.size() == 0){
        username = "Client";
    }
    return username;
}

ChatProtocol ClientManager::getProtocol()
{
    return _protocol;
}
//отправляем данные на сервер
void ClientManager::readyRead()
{
    auto data = _socket->readAll();
    _protocol.loadData(data);
    switch (_protocol.type()) {
    case ChatProtocol::Text:
        emit textMessageReceived(_protocol.message());
        break;
    case ChatProtocol::SetUsername:
        emit createUsername(_protocol.username());
        break;
    case ChatProtocol::SetPassword:
        emit createPassword(_protocol.password());
        break;
    case ChatProtocol::IsTyping:
        emit isTyping();
        break;
    case ChatProtocol::ErrorRegistration:
        emit createErrorRegistration(_protocol.errorRegistrationMessage());
        break;
    case ChatProtocol::IsLogged:
        emit isLogged();
        break;
    default:
        break;
    }
}
