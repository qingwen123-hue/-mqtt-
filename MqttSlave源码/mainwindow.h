#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "mqtt/qmqtt.h"
#include <QtNetwork>
#include <QHostAddress>
#include <QMessageBox>
#include <QBuffer>
#include <QDebug>
#include "mqtt/qmqtt_client.h"
#include <string.h>
#include "sendorderwindow.h"
struct DishClass
{
    int grade;
    QString name;
    QPixmap pix;
};
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    void ClientPub(QString Toipe,QString pubmessage);

    void LoadData();

    void on_ConButton_clicked();

    void connectSuccessSlot();

    //void received(const QMQTT::Message& message);
    void recxMessageSlot(const QMQTT::Message& message);


    void ReceiveChild(bool i);

    void on_SenButton_clicked();

    void on_PrePagesButton_clicked();

    void on_NexPagesButton_clicked();

    void OrdNum_Page();

signals:
    void SendOrderTChild(QString text);

private:
    Ui::MainWindow *ui;
    QMQTT::Client *client;
    DishClass Dishes[30];
    int ReFlag;
    int DishNum;
    int Pages;
    int MaxPages;
    int OrdNum[30];
    QMap<int,int>  OrdNumList;
    SendOrderWindow *senwi;
    QString SendHostOrder;
};
#endif // MAINWINDOW_H
