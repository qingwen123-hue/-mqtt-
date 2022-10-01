/********************************************************************************
** Form generated from reading UI file 'deletedishwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEDISHWINDOW_H
#define UI_DELETEDISHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeleteDishWindow
{
public:
    QWidget *centralwidget;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DeleteDishWindow)
    {
        if (DeleteDishWindow->objectName().isEmpty())
            DeleteDishWindow->setObjectName(QString::fromUtf8("DeleteDishWindow"));
        DeleteDishWindow->resize(800, 600);
        centralwidget = new QWidget(DeleteDishWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(20, 10, 111, 22));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(160, 10, 121, 31));
        DeleteDishWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DeleteDishWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        DeleteDishWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(DeleteDishWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DeleteDishWindow->setStatusBar(statusbar);

        retranslateUi(DeleteDishWindow);

        QMetaObject::connectSlotsByName(DeleteDishWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DeleteDishWindow)
    {
        DeleteDishWindow->setWindowTitle(QApplication::translate("DeleteDishWindow", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("DeleteDishWindow", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeleteDishWindow: public Ui_DeleteDishWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEDISHWINDOW_H
