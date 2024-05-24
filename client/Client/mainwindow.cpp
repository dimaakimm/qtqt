#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <ChatItemWidget.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralwidget->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionConnect_triggered()
{
        _client = new ClientManager();
        connect(_client, &ClientManager::connected, [this](){
            ui -> centralwidget->setEnabled(true);
        });
        connect(_client, &ClientManager::disconnected, [this](){
            ui -> centralwidget->setEnabled(false);
        });
        connect(_client, &ClientManager::textMessageReceived, this, &MainWindow::dataReceived);
        connect(_client, &ClientManager::isTyping, this, &MainWindow::onTyping);
        connect(ui->lnMessage, &QLineEdit::textChanged, _client, &ClientManager::sendIsTyping);
        _client->connectToServer();

}


void MainWindow::on_actionExit_triggered()
{

}

void MainWindow::dataReceived(QString message)
{
    //ui -> lstMessages->addItem(data);
    auto chatWidget = new ChatItemWidget(this);
    chatWidget->setMessage(message);
    auto listItemWidget = new QListWidgetItem();
    listItemWidget->setSizeHint(QSize(0, 65));
    ui->lstMessages->addItem(listItemWidget);
    ui -> lstMessages->setItemWidget(listItemWidget, chatWidget);
}


void MainWindow::on_btnSend_clicked()
{
    auto message = ui->lnMessage->text().trimmed();
    _client->sendMessage(message);
   // ui -> lstMessages->addItem(message);
    ui -> lnMessage->setText("");
    ui -> lnMessage->setFocus();

    auto chatWidget = new ChatItemWidget(this);
    chatWidget->setMessage(message, true);
    auto listItemWidget = new QListWidgetItem();
    listItemWidget->setSizeHint(QSize(0, 65));
    ui->lstMessages->addItem(listItemWidget);
    ui -> lstMessages->setItemWidget(listItemWidget, chatWidget);
}



//кнопка регистрации

void MainWindow::on_btnAuth_clicked()
{
    auto username = ui->lnUsername->text().trimmed();
    auto password = ui->lnPassword->text().trimmed();
    if (username.size() < 3 || password.size() < 3){
        ui->lnUsername->setText("Error");
        ui->lnPassword->setText("Error");
    //show error
    }
    else if (auth==false){
        auth = true;
        _client -> sendUsername(username);
        _client -> sendPassword(password);
        _client->sendIsLogged();


        //edit auh to logged in
        ui ->lnPassword->setVisible(0);
        ui ->lnUsername->setVisible(0);
        ui->label_2->setVisible(0);
        ui->label_3->setText(QString("You're now logged as: %1").arg(username));
        ui ->groupBox_2 ->setTitle("Condition");
        ui->btnAuth->setText("Exit");
    }
    else{
        auth = false;
        _client->sendIsLogged();
        ui ->btnAuth->setText("Auth");
        ui->lnUsername->setVisible(1);
        ui ->lnPassword->setVisible(1);
        ui->label_2->setVisible(1);
        ui->label_3->setText("Username:");
        ui ->groupBox_2 ->setTitle("Auth");
    }


}

void MainWindow::onTyping()
{
    statusBar() -> showMessage("Server is typing...", 750);
}

