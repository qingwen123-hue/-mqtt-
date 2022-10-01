/********************************************************************************
** Form generated from reading UI file 'dishwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISHWINDOW_H
#define UI_DISHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dishwindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Dishwindow)
    {
        if (Dishwindow->objectName().isEmpty())
            Dishwindow->setObjectName(QString::fromUtf8("Dishwindow"));
        Dishwindow->resize(800, 600);
        centralwidget = new QWidget(Dishwindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 40, 91, 41));
        Dishwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Dishwindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Dishwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(Dishwindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Dishwindow->setStatusBar(statusbar);

        retranslateUi(Dishwindow);

        QMetaObject::connectSlotsByName(Dishwindow);
    } // setupUi

    void retranslateUi(QMainWindow *Dishwindow)
    {
        Dishwindow->setWindowTitle(QApplication::translate("Dishwindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("Dishwindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dishwindow: public Ui_Dishwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISHWINDOW_H
