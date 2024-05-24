#include "ServerManager.h"
#include <QtNetwork>
ServerManager::ServerManager(ushort port, QObject *parent)
    : QObject{parent}
{
    setupServer(port);
}
//подключение
void ServerManager::newClientConnectionReceived() {
    auto client = _server->nextPendingConnection(); //след подключение
    _clients << client;
    auto id = _clients.length();
    client->setProperty("id", id);
    connect(client, &QTcpSocket::disconnected, this, &ServerManager::onClientDisconnected);
    emit newClientConnected(client);
}
//отключение
void ServerManager::onClientDisconnected() {
    auto client = qobject_cast<QTcpSocket *>(sender());//приводит отправителя к действию
//    int id = client->property("id").toInt();
    _clients.removeOne(client);
    emit clientDisconnected(client);
}

//запуск сервера
void ServerManager::setupServer(ushort port) {
    _server = new QTcpServer(this);
    connect(_server, &QTcpServer::newConnection, this, &ServerManager::newClientConnectionReceived);
    _server->listen(QHostAddress::Any, port); //прослушиваем любой ip адрес моего компьютера
}
