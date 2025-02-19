#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ClientManager.h"
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
    void on_actionConnect_triggered();
    void on_actionExit_triggered();
    void dataReceived(QString message);

    void on_btnSend_clicked();

    void on_btnAuth_clicked();

    void onTyping();

private:
    Ui::MainWindow *ui;
    ClientManager *_client;
    bool auth = false;
};
#endif // MAINWINDOW_H
