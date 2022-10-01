/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *connectButton;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QLabel *img1;
    QLabel *name1;
    QLabel *name2;
    QLabel *img2;
    QLabel *name3;
    QLabel *name4;
    QLabel *img4;
    QLabel *img3;
    QPushButton *AddDishButton;
    QPushButton *DeleteDishButton;
    QPushButton *PrePagesButton;
    QPushButton *NexPagesButton;
    QLabel *Pages;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1030, 560);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        connectButton = new QPushButton(centralwidget);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setGeometry(QRect(10, 10, 111, 31));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(290, 60, 256, 192));
        textBrowser_2 = new QTextBrowser(centralwidget);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(10, 60, 256, 192));
        img1 = new QLabel(centralwidget);
        img1->setObjectName(QString::fromUtf8("img1"));
        img1->setGeometry(QRect(30, 290, 200, 200));
        name1 = new QLabel(centralwidget);
        name1->setObjectName(QString::fromUtf8("name1"));
        name1->setGeometry(QRect(70, 500, 111, 21));
        name2 = new QLabel(centralwidget);
        name2->setObjectName(QString::fromUtf8("name2"));
        name2->setGeometry(QRect(280, 500, 121, 21));
        img2 = new QLabel(centralwidget);
        img2->setObjectName(QString::fromUtf8("img2"));
        img2->setGeometry(QRect(250, 290, 200, 200));
        name3 = new QLabel(centralwidget);
        name3->setObjectName(QString::fromUtf8("name3"));
        name3->setGeometry(QRect(510, 500, 91, 21));
        name4 = new QLabel(centralwidget);
        name4->setObjectName(QString::fromUtf8("name4"));
        name4->setGeometry(QRect(740, 500, 81, 21));
        img4 = new QLabel(centralwidget);
        img4->setObjectName(QString::fromUtf8("img4"));
        img4->setGeometry(QRect(690, 290, 200, 200));
        img3 = new QLabel(centralwidget);
        img3->setObjectName(QString::fromUtf8("img3"));
        img3->setGeometry(QRect(470, 290, 200, 200));
        AddDishButton = new QPushButton(centralwidget);
        AddDishButton->setObjectName(QString::fromUtf8("AddDishButton"));
        AddDishButton->setGeometry(QRect(140, 10, 111, 31));
        DeleteDishButton = new QPushButton(centralwidget);
        DeleteDishButton->setObjectName(QString::fromUtf8("DeleteDishButton"));
        DeleteDishButton->setGeometry(QRect(270, 10, 101, 31));
        PrePagesButton = new QPushButton(centralwidget);
        PrePagesButton->setObjectName(QString::fromUtf8("PrePagesButton"));
        PrePagesButton->setGeometry(QRect(930, 319, 81, 31));
        NexPagesButton = new QPushButton(centralwidget);
        NexPagesButton->setObjectName(QString::fromUtf8("NexPagesButton"));
        NexPagesButton->setGeometry(QRect(930, 420, 81, 31));
        Pages = new QLabel(centralwidget);
        Pages->setObjectName(QString::fromUtf8("Pages"));
        Pages->setGeometry(QRect(940, 370, 71, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1030, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        connectButton->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", nullptr));
        img1->setText(QString());
        name1->setText(QString());
        name2->setText(QString());
        img2->setText(QString());
        name3->setText(QString());
        name4->setText(QString());
        img4->setText(QString());
        img3->setText(QString());
        AddDishButton->setText(QApplication::translate("MainWindow", "\345\242\236\345\212\240\350\217\234\345\223\201", nullptr));
        DeleteDishButton->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\350\217\234\345\223\201", nullptr));
        PrePagesButton->setText(QApplication::translate("MainWindow", "\344\270\212\344\270\200\351\241\265", nullptr));
        NexPagesButton->setText(QApplication::translate("MainWindow", "\344\270\213\344\270\200\351\241\265", nullptr));
        Pages->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
