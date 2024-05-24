

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupServer();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//с ServerManager принимаем клиента и создаем подключение
void MainWindow::newClientConnected(QTcpSocket *client)
{
    //также занимаемся передачей данный в ui
    auto id = client->property("id").toInt();
    ui -> lstClients -> addItem(QString("New client added : %1").arg(id));
    //при каждом соеднинении создаем виджет чата
    auto chatWidget = new ClientChatWidget(client);
    ui->tbChats->addTab(chatWidget, QString("Client %1").arg(id));
    connect(chatWidget, &ClientChatWidget::createUsername, this, &MainWindow::setUsername);
    connect(chatWidget, &ClientChatWidget::isTyping, [this](QString username){
        this->statusBar()->showMessage(username, 750);
    });
     connect(chatWidget, &ClientChatWidget::isLogged, [this](QString username){
        this->statusBar()->showMessage(username, 750);
    });
}

void MainWindow::clientDisconnected(QTcpSocket *client)
{
    auto id = client->property("id").toInt();
    ui -> lstClients -> addItem(QString("Client disconnected").arg(id));
}

void MainWindow::setUsername(QString username)
{
    auto widget = qobject_cast<QWidget *>(sender());
    auto index = ui->tbChats->indexOf(widget);
    ui->tbChats->setTabText(index, username);

}

void MainWindow::setupServer()
{
    _server  = new ServerManager();
    //принимаем сигналы
    connect(_server, &ServerManager::newClientConnected, this, &MainWindow::newClientConnected);
    connect(_server, &ServerManager::clientDisconnected, this, &MainWindow::clientDisconnected);
}
