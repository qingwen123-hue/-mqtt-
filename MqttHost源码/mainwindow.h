#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMqtt/qmqttclient.h>
#include <string.h>
#include <QBuffer>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "adddhiswindow.h"
#include <QSqlQuery>
#include "deletedishwindow.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#define TheMotif (QString)"mqtt"
struct DishClass
{
    int grade;
    QString name;
    QPixmap pix;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void SendDishDel(QStringList names);

private slots:
    void on_connectButton_clicked();

    void connectSuccessSlot();

    void recxMessageSlot(const QByteArray &ba,const QMqttTopicName &topic);

    QByteArray ImgToQByteArray(QPixmap pixmap);

    QString ImgToQString(QPixmap pixmap);

    void DataReLoad();

    void on_AddDishButton_clicked();

    void ReceiveData(QString name,QString img_file);

    void on_DeleteDishButton_clicked();

    void DeleteDish(QString name);

    void on_PrePagesButton_clicked();

    void on_NexPagesButton_clicked();

private:
    Ui::MainWindow *ui;
    QMqttClient *client;
    QMap<QString,int> TocipList;
    QStringList OrderList;
    QSqlDatabase db;
    int DishNum;
    DishClass Dishes[30];
    AddDhisWindow *addwi;
    DeleteDishWindow *delwi;
    int Pages;
    int MaxPages;
};



#endif // MAINWINDOW_H
