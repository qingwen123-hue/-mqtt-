/********************************************************************************
** Form generated from reading UI file 'sendorderwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDORDERWINDOW_H
#define UI_SENDORDERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SendOrderWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *confirmButton;
    QPushButton *cancelButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SendOrderWindow)
    {
        if (SendOrderWindow->objectName().isEmpty())
            SendOrderWindow->setObjectName(QString::fromUtf8("SendOrderWindow"));
        SendOrderWindow->resize(514, 234);
        centralwidget = new QWidget(SendOrderWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 30, 421, 81));
        confirmButton = new QPushButton(centralwidget);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setGeometry(QRect(100, 140, 91, 31));
        cancelButton = new QPushButton(centralwidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(250, 140, 91, 31));
        SendOrderWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SendOrderWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 514, 23));
        SendOrderWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SendOrderWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SendOrderWindow->setStatusBar(statusbar);

        retranslateUi(SendOrderWindow);

        QMetaObject::connectSlotsByName(SendOrderWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SendOrderWindow)
    {
        SendOrderWindow->setWindowTitle(QApplication::translate("SendOrderWindow", "MainWindow", nullptr));
        label->setText(QString());
        confirmButton->setText(QApplication::translate("SendOrderWindow", "confirm", nullptr));
        cancelButton->setText(QApplication::translate("SendOrderWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SendOrderWindow: public Ui_SendOrderWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDORDERWINDOW_H
