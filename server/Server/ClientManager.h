#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include <ChatProtocol.h>
#include <QObject>
#include<QTcpSocket>
//подключение к серверу и получение - отправка данных
class ClientManager : public QObject
{
    Q_OBJECT
public:
    explicit ClientManager(QHostAddress ip = QHostAddress::LocalHost,
                           ushort port = 3000, QObject *parent = nullptr);
    explicit ClientManager(QTcpSocket *client, QObject *parent = nullptr);
    //подключение
    void connectToServer();
    //отпарвка сообщений
    void sendMessage(QString message);
    void sendErrorRegistration(QString errorMessage);
    void sendUsername(QString username);
    void sendPassword(QString password);
    //метод во время печати сообщений
    void sendIsTyping();
    void sendIsLogged();
    QString username() const;
    ChatProtocol getProtocol();
    //отправляем сигналы
signals:
    void connected();
    void disconnected();
    //    void dataReceived(QByteArray data);
    //передаем данные на сервер
    void createErrorRegistration(QString message);
    void textMessageReceived(QString message);
    void isTyping();
    void createUsername(QString username);
    void createPassword(QString password);
    void isLogged();
private slots:
    void readyRead();
private:
    QTcpSocket *_socket;
    QHostAddress _ip;
    ushort _port;
    //используем протокол для отправки сообщений нужного типа
    ChatProtocol _protocol;
};

#endif // CLIENTMANAGER_H
