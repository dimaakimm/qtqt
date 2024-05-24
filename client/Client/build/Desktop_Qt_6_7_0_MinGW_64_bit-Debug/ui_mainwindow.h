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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConnect;
    QAction *actionExit;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lnUsername;
    QLabel *label_2;
    QLineEdit *lnPassword;
    QPushButton *btnAuth;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *lstMessages;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lnMessage;
    QPushButton *btnSend;
    QMenuBar *menubar;
    QMenu *menuOptions;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(832, 457);
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName("actionConnect");
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        lnUsername = new QLineEdit(groupBox_2);
        lnUsername->setObjectName("lnUsername");

        horizontalLayout_3->addWidget(lnUsername);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName("label_2");

        horizontalLayout_3->addWidget(label_2);

        lnPassword = new QLineEdit(groupBox_2);
        lnPassword->setObjectName("lnPassword");

        horizontalLayout_3->addWidget(lnPassword);

        btnAuth = new QPushButton(groupBox_2);
        btnAuth->setObjectName("btnAuth");

        horizontalLayout_3->addWidget(btnAuth);


        verticalLayout->addWidget(groupBox_2);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lstMessages = new QListWidget(groupBox);
        lstMessages->setObjectName("lstMessages");

        horizontalLayout_2->addWidget(lstMessages);


        verticalLayout->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        lnMessage = new QLineEdit(centralwidget);
        lnMessage->setObjectName("lnMessage");

        horizontalLayout->addWidget(lnMessage);

        btnSend = new QPushButton(centralwidget);
        btnSend->setObjectName("btnSend");

        horizontalLayout->addWidget(btnSend);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 832, 25));
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName("menuOptions");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuOptions->menuAction());
        menuOptions->addAction(actionConnect);
        menuOptions->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Auth", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Username:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        btnAuth->setText(QCoreApplication::translate("MainWindow", "Auth!", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Messages", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Message:", nullptr));
        btnSend->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        menuOptions->setTitle(QCoreApplication::translate("MainWindow", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
