#include "ClientChatWidget.h"
#include "ui_ClientChatWidget.h"

ClientChatWidget::ClientChatWidget(QTcpSocket *client, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ClientChatWidget)
{
    ui->setupUi(this);
    _client = new ClientManager(client, this);
//    connect(_client, &QTcpSocket::readyRead, this, &ClientChatWidget::dataReceived);
    connect(_client, &ClientManager::disconnected, this, &ClientChatWidget::clientDisconnected);
    connect(_client, &ClientManager::textMessageReceived, this, &ClientChatWidget::textMessageReceived);
    connect(_client, &ClientManager::isTyping, this, &ClientChatWidget::onTyping);
    connect(_client, &ClientManager::isLogged, this, &ClientChatWidget::onLogged);
    connect(_client, &ClientManager::createUsername, this, &ClientChatWidget::createUsername);
    connect(_client, &ClientManager::createPassword, this, &ClientChatWidget::createPassword);
    connect(ui->lnMessage, &QLineEdit::textChanged, _client, &ClientManager::sendIsTyping);
}



ClientChatWidget::~ClientChatWidget()
{
    delete ui;
}

//отправляем сообщение благодаря кнопки send
void ClientChatWidget::on_btnSend_clicked()
{
    auto message = ui -> lnMessage -> text().trimmed();
    _client->sendMessage(ui->lnMessage->text().trimmed());
    ui->lnMessage->setText("");
    ui->lstMessages->addItem(message);
}

void ClientChatWidget::clientDisconnected()
{
    ui -> wdgSend -> setEnabled(false);
}

void ClientChatWidget::textMessageReceived(QString message)
{
    ui->lstMessages->addItem(message);
}

void ClientChatWidget::onTyping()
{
    emit isTyping(QString("%1 is typing..").arg(_client->username()));
}
void ClientChatWidget::onLogged()
{
    emit isLogged(QString("%1 is typing..").arg(_client->username()));
}


