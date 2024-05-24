#ifndef CHATPROTOCOL_H
#define CHATPROTOCOL_H

#include <QString>

//класс для передачи сообщений определенного типа
class ChatProtocol
{
public:
    //типы
    enum MessageType {
        Text,
        IsTyping,
        SetPassword,
        SetUsername,
        IsLogged
    };
    ChatProtocol();
    QByteArray textMessage(QString message);
    QByteArray isTypingMessage();
    QByteArray setPasswordMessage(QString password);
    QByteArray setUsernameMessage(QString username);
    QByteArray isTypingLogged();
    //получение данных
    void loadData(QByteArray data);
    QString message() const;

    QString username() const;
    void setUsername(const QString &newUsername);

    QString password() const;
    void setPassword(const QString &newPassword);

    MessageType type() const
    {
        return _type;
    }

signals:
    void usernameChanged();

    void passwordChanged();

private:
    //получение данных по типу
    QByteArray getData(MessageType type, QString data);
    //тип принимаемого сообщения
    MessageType _type;
    QString _message;
    QString _username;
    QString _password;
    Q_PROPERTY(QString username READ username WRITE setUsername NOTIFY usernameChanged FINAL)
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged FINAL)
};

#endif // CHATPROTOCOL_H
