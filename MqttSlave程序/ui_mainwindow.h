/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *img1;
    QLabel *name1;
    QSpinBox *spinBox1;
    QLabel *name2;
    QLabel *img2;
    QSpinBox *spinBox2;
    QLabel *name3;
    QLabel *img4;
    QLabel *img3;
    QLabel *name4;
    QSpinBox *spinBox4;
    QSpinBox *spinBox3;
    QTextBrowser *textBrowser;
    QPushButton *ConButton;
    QPushButton *SenButton;
    QPushButton *PrePagesButton;
    QPushButton *NexPagesButton;
    QLabel *Pages;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 480);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        img1 = new QLabel(centralwidget);
        img1->setObjectName(QString::fromUtf8("img1"));
        img1->setGeometry(QRect(10, 0, 200, 200));
        name1 = new QLabel(centralwidget);
        name1->setObjectName(QString::fromUtf8("name1"));
        name1->setGeometry(QRect(220, 10, 81, 31));
        spinBox1 = new QSpinBox(centralwidget);
        spinBox1->setObjectName(QString::fromUtf8("spinBox1"));
        spinBox1->setGeometry(QRect(220, 40, 81, 71));
        name2 = new QLabel(centralwidget);
        name2->setObjectName(QString::fromUtf8("name2"));
        name2->setGeometry(QRect(520, 10, 81, 31));
        img2 = new QLabel(centralwidget);
        img2->setObjectName(QString::fromUtf8("img2"));
        img2->setGeometry(QRect(310, 0, 200, 200));
        spinBox2 = new QSpinBox(centralwidget);
        spinBox2->setObjectName(QString::fromUtf8("spinBox2"));
        spinBox2->setGeometry(QRect(520, 40, 81, 71));
        name3 = new QLabel(centralwidget);
        name3->setObjectName(QString::fromUtf8("name3"));
        name3->setGeometry(QRect(220, 230, 81, 31));
        img4 = new QLabel(centralwidget);
        img4->setObjectName(QString::fromUtf8("img4"));
        img4->setGeometry(QRect(310, 220, 200, 200));
        img3 = new QLabel(centralwidget);
        img3->setObjectName(QString::fromUtf8("img3"));
        img3->setGeometry(QRect(10, 220, 200, 200));
        name4 = new QLabel(centralwidget);
        name4->setObjectName(QString::fromUtf8("name4"));
        name4->setGeometry(QRect(520, 190, 81, 31));
        spinBox4 = new QSpinBox(centralwidget);
        spinBox4->setObjectName(QString::fromUtf8("spinBox4"));
        spinBox4->setGeometry(QRect(520, 220, 81, 61));
        spinBox3 = new QSpinBox(centralwidget);
        spinBox3->setObjectName(QString::fromUtf8("spinBox3"));
        spinBox3->setGeometry(QRect(220, 260, 81, 71));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(520, 300, 256, 131));
        ConButton = new QPushButton(centralwidget);
        ConButton->setObjectName(QString::fromUtf8("ConButton"));
        ConButton->setGeometry(QRect(640, 20, 101, 41));
        SenButton = new QPushButton(centralwidget);
        SenButton->setObjectName(QString::fromUtf8("SenButton"));
        SenButton->setGeometry(QRect(640, 70, 101, 41));
        PrePagesButton = new QPushButton(centralwidget);
        PrePagesButton->setObjectName(QString::fromUtf8("PrePagesButton"));
        PrePagesButton->setGeometry(QRect(640, 130, 111, 41));
        NexPagesButton = new QPushButton(centralwidget);
        NexPagesButton->setObjectName(QString::fromUtf8("NexPagesButton"));
        NexPagesButton->setGeometry(QRect(640, 210, 111, 41));
        Pages = new QLabel(centralwidget);
        Pages->setObjectName(QString::fromUtf8("Pages"));
        Pages->setGeometry(QRect(650, 180, 101, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
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
        img1->setText(QString());
        name1->setText(QString());
        name2->setText(QString());
        img2->setText(QString());
        name3->setText(QString());
        img4->setText(QString());
        img3->setText(QString());
        name4->setText(QString());
        ConButton->setText(QApplication::translate("MainWindow", "ConnectHost", nullptr));
        SenButton->setText(QApplication::translate("MainWindow", "SendOrder", nullptr));
        PrePagesButton->setText(QApplication::translate("MainWindow", "Pre", nullptr));
        NexPagesButton->setText(QApplication::translate("MainWindow", "Nex", nullptr));
        Pages->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
