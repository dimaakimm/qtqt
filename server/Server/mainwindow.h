#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ClientChatWidget.h"
#include <QMainWindow>
#include "ServerManager.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    //с ServerManager принимаем клиента и создаем подключение
    void newClientConnected(QTcpSocket *client);
    void clientDisconnected(QTcpSocket *client);
    void setUsername(QString username);
private:
    Ui::MainWindow *ui;
    ServerManager *_server;

private: //methods
    void setupServer();
};


#endif // MAINWINDOW_H
