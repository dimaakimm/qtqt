#include "ChatProtocol.h"

#include <QIODevice>

ChatProtocol::ChatProtocol() {}

QByteArray ChatProtocol::textMessage(QString message)
{
    return getData(Text, message);
}

QByteArray ChatProtocol::isTypingMessage()
{
    return getData(IsTyping, "");
}
QByteArray ChatProtocol::isTypingLogged(){
    return getData(IsLogged,"");
}
QByteArray ChatProtocol::setPasswordMessage(QString password)
{
    return getData(SetPassword, password);
}

QByteArray ChatProtocol::setUsernameMessage(QString username)
{
    return getData(SetUsername, username);
}

void ChatProtocol::loadData(QByteArray data)
{
    QDataStream in (&data, QIODevice::ReadOnly);
    in.setVersion(QDataStream::Qt_6_0);
    in >> _type;
    switch (_type) {
    case Text:
        in >> _message;
        break;
    case SetUsername:
        in >> _username;
        break;
    case SetPassword:
        in >> _password;
        break;
    default:
        break;
    }
}

QByteArray ChatProtocol::getData(MessageType type, QString data)
{
    QByteArray ba;
    QDataStream out(&ba, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_0);
    out << type << data;
    return ba;
}



QString ChatProtocol::password() const
{
    return _password;
}

QString ChatProtocol::username() const
{
    return _username;
}

QString ChatProtocol::message() const
{
    return _message;
}
