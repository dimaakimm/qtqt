#ifndef CLIENTCHATWIDGET_H
#define CLIENTCHATWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <ClientManager.h>
namespace Ui {
class ClientChatWidget;
}

class ClientChatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClientChatWidget(QTcpSocket *client, QWidget *parent = nullptr);
    ~ClientChatWidget();
private slots:
    void on_btnSend_clicked();
    void clientDisconnected();
    void textMessageReceived(QString message);
    void onTyping();
    void onLogged();
signals:
    void createUsername(QString username);
    void isTyping(QString message);
    void createPassword(QString password);
    void isLogged(QString message);
private:
    Ui::ClientChatWidget *ui;
    ClientManager *_client;
};

#endif // CLIENTCHATWIDGET_H
