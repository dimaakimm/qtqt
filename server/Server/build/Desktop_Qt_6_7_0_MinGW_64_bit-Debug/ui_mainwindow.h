/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *grpClients;
    QListWidget *lstClients;
    QGroupBox *grpChats;
    QVBoxLayout *verticalLayout;
    QTabWidget *tbChats;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(734, 448);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        grpClients = new QGroupBox(centralwidget);
        grpClients->setObjectName("grpClients");
        grpClients->setGeometry(QRect(10, 0, 191, 361));
        grpClients->setAlignment(Qt::AlignCenter);
        lstClients = new QListWidget(grpClients);
        lstClients->setObjectName("lstClients");
        lstClients->setGeometry(QRect(0, 30, 191, 321));
        grpChats = new QGroupBox(centralwidget);
        grpChats->setObjectName("grpChats");
        grpChats->setGeometry(QRect(220, 0, 501, 381));
        grpChats->setAlignment(Qt::AlignCenter);
        verticalLayout = new QVBoxLayout(grpChats);
        verticalLayout->setObjectName("verticalLayout");
        tbChats = new QTabWidget(grpChats);
        tbChats->setObjectName("tbChats");

        verticalLayout->addWidget(tbChats);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 734, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tbChats->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        grpClients->setTitle(QCoreApplication::translate("MainWindow", "List of Clients", nullptr));
        grpChats->setTitle(QCoreApplication::translate("MainWindow", "Chats", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
