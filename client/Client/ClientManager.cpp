#include "ClientManager.h"

ClientManager::ClientManager(QHostAddress ip, ushort port, QObject *parent)
    : QObject{parent}, _ip(ip), _port(port)
{
    _socket = new QTcpSocket(this);
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

void ClientManager::sendUsername(QString username)
{
    _socket->write(_protocol.setUsernameMessage(username));
}

void ClientManager::sendPassword(QString password)
{
    _socket->write(_protocol.setPasswordMessage(password));
}
void ClientManager::sendIsLogged()
{
    //_socket->write(_protocol.textMessage("Adaf"));
    _socket->write(_protocol.isTypingLogged());
}
void ClientManager::sendIsTyping()
{
    _socket->write(_protocol.isTypingMessage());
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
    case ChatProtocol::IsLogged:
        emit isLogged();
        break;
    default:
        break;
    }
}

