#ifndef SERVERMANAGER_H
#define SERVERMANAGER_H

#include <QObject>
#include <QTcpServer>
//занимается работой с подключением / отключением клиентов и взаимодействием клиента и сервера
class ServerManager : public QObject
{
    Q_OBJECT
public:
    explicit ServerManager(ushort port = 3000, QObject *parent = nullptr);

private slots:
    void newClientConnectionReceived();
    void onClientDisconnected();

signals:
    void newClientConnected(QTcpSocket *client);
    void clientDisconnected(QTcpSocket *client);
private : //методы
    void setupServer(ushort port); //настройка сервера
private : //поля
    QTcpServer *_server;
    QList<QTcpSocket *> _clients;

};

#endif // SERVERMANAGER_H
