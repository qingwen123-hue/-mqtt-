/********************************************************************************
** Form generated from reading UI file 'adddhiswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDHISWINDOW_H
#define UI_ADDDHISWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddDhisWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *DishNameEdit;
    QLineEdit *ImgFileEdit;
    QPushButton *ImgFileButton;
    QPushButton *OKButton;
    QPushButton *NoButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AddDhisWindow)
    {
        if (AddDhisWindow->objectName().isEmpty())
            AddDhisWindow->setObjectName(QString::fromUtf8("AddDhisWindow"));
        AddDhisWindow->resize(426, 180);
        centralwidget = new QWidget(AddDhisWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 81, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 50, 91, 31));
        DishNameEdit = new QLineEdit(centralwidget);
        DishNameEdit->setObjectName(QString::fromUtf8("DishNameEdit"));
        DishNameEdit->setGeometry(QRect(130, 20, 131, 20));
        ImgFileEdit = new QLineEdit(centralwidget);
        ImgFileEdit->setObjectName(QString::fromUtf8("ImgFileEdit"));
        ImgFileEdit->setGeometry(QRect(130, 50, 131, 20));
        ImgFileButton = new QPushButton(centralwidget);
        ImgFileButton->setObjectName(QString::fromUtf8("ImgFileButton"));
        ImgFileButton->setGeometry(QRect(270, 50, 91, 31));
        OKButton = new QPushButton(centralwidget);
        OKButton->setObjectName(QString::fromUtf8("OKButton"));
        OKButton->setGeometry(QRect(10, 100, 91, 31));
        NoButton = new QPushButton(centralwidget);
        NoButton->setObjectName(QString::fromUtf8("NoButton"));
        NoButton->setGeometry(QRect(120, 100, 101, 31));
        AddDhisWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AddDhisWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 426, 21));
        AddDhisWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AddDhisWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AddDhisWindow->setStatusBar(statusbar);

        retranslateUi(AddDhisWindow);

        QMetaObject::connectSlotsByName(AddDhisWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AddDhisWindow)
    {
        AddDhisWindow->setWindowTitle(QApplication::translate("AddDhisWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("AddDhisWindow", "\350\217\234\345\223\201\345\220\215\347\247\260", nullptr));
        label_2->setText(QApplication::translate("AddDhisWindow", "\350\217\234\345\223\201\345\233\276\345\203\217\350\267\257\345\276\204", nullptr));
        ImgFileButton->setText(QApplication::translate("AddDhisWindow", "\346\234\254\345\234\260\346\237\245\346\211\276", nullptr));
        OKButton->setText(QApplication::translate("AddDhisWindow", "\345\256\214\346\210\220", nullptr));
        NoButton->setText(QApplication::translate("AddDhisWindow", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddDhisWindow: public Ui_AddDhisWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDHISWINDOW_H
