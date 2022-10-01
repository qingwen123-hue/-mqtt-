#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#define HostIP "192.168.1.201"
#define UseName "test"
#define Pass "123456"
#define TheMotif (QString)"mqtt"
#define MeTopic (QString)"01"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textBrowser->close();
    client = new QMQTT::Client;

    client->setHostName(HostIP);
    client->setPort(1883);
    client->setUsername(UseName);
    client->setPassword(Pass);

    connect(client,&QMQTT::Client::connected,this,&MainWindow::connectSuccessSlot);

    for(int h =0 ;h<30;h++)
    {
        OrdNum[h]=0;
    }

    DishNum=1;
    Pages = 1;
    LoadData();
    DishNum=0;
}

MainWindow::~MainWindow()
{
    ClientPub(MeTopic,(QString)"Offline");
    client->disconnectFromHost();
    delete ui;
}

void MainWindow::on_ConButton_clicked()
{
    client->connectToHost();
}

void MainWindow::connectSuccessSlot()
{
    ui->textBrowser->append("连接服务器成功");
    client->subscribe(TheMotif);
    ui->textBrowser->append("订阅"+TheMotif+"主题成功");
    client->subscribe(MeTopic+"_t");
    ui->textBrowser->append("订阅"+MeTopic+"_t"+"主题成功");
    connect(client,&QMQTT::Client::received,this,&MainWindow::recxMessageSlot);
    connect(client,&QMQTT::Client::disconnected,[this]()
    {
        QMessageBox::information(this,"连接提示","服务器断开");
    });

    QByteArray ba;
    ba.append(MeTopic);
    QMQTT::Message message(0,TheMotif,ba);
    client->publish(message);

}

void MainWindow::recxMessageSlot(const QMQTT::Message& message)
{

//    QString str = message.topic() + ':' + message.payload();
//    ui->textBrowser->setText(str);
    QString str = message.payload();
    QByteArray ba;
    ba.append(message.payload());

    ui->textBrowser->append("接收到  "+ message.topic() + ':' + str);
    if(message.topic() == MeTopic + "_t")
    {
        if(str == "OK")
        {
            client->unsubscribe(TheMotif);
            ui->textBrowser->append("断开与"+TheMotif+"主题连接");
            ReFlag = 1;
            ui->textBrowser->append("111");
            ClientPub(MeTopic,(QString)"OK_t");
            ui->textBrowser->append("2222");
        }
        else if(ReFlag == 1)
        {
            Dishes[DishNum].grade=ba.toInt();
            ReFlag = 2;
            ClientPub(MeTopic,(QString)"grade_t");
        }
        else if(ReFlag == 2)
        {
            Dishes[DishNum].name = (QString)ba;
            //strcpy( Dishes[DishNum].name, ba);
            ReFlag = 3;
            ClientPub(MeTopic,(QString)"name_t");
        }
        else if(ReFlag == 3)
        {
            Dishes[DishNum].pix.loadFromData(ba,"JPG");
            ReFlag = 4;
            ClientPub(MeTopic,(QString)"img_t");
        }
        else if(str == "TransferIncomplete")
        {
            DishNum++;
            ReFlag = 1;
            ClientPub(MeTopic,(QString)"OK_t");
            //LoadData();
        }
        else if(str == "TransferComplete")
        {
            DishNum++;
            LoadData();
        }

    }
}

void MainWindow::ClientPub(QString Toipe, QString pubmessage)
{
    QByteArray ba_pub;
    ba_pub.append(pubmessage);
    QMQTT::Message message(0,Toipe,ba_pub);
    client->publish(message);
}

void MainWindow::LoadData()
{
    int i = DishNum % 4;
    if(i == 0)
    {
        MaxPages = DishNum/4;
    }
    else
    {
        MaxPages = DishNum/4 + 1;
    }
    if(Pages>MaxPages)Pages = MaxPages;
    ui->img1->clear();
    ui->name1->clear();
    ui->img2->clear();
    ui->name2->clear();
    ui->img3->clear();
    ui->name3->clear();
    ui->img4->clear();
    ui->name4->clear();
    if(Pages == MaxPages && i !=0)
    {
        ui->img1->setPixmap(Dishes[(Pages-1)*4 + 0].pix);
        ui->name1->setText(Dishes[(Pages-1)*4 + 0].name);
        ui->spinBox1->setValue(OrdNum[(Pages-1)*4 + 0]);
        if(i>=2)
        {
            ui->img2->setPixmap(Dishes[(Pages-1)*4 + 1].pix);
            ui->name2->setText(Dishes[(Pages-1)*4 + 1].name);
            ui->spinBox2->setValue(OrdNum[(Pages-1)*4 + 1]);
        }

        if(i>=3)
        {
            ui->img3->setPixmap(Dishes[(Pages-1)*4 + 2].pix);
            ui->name3->setText(Dishes[(Pages-1)*4 + 2].name);
            ui->spinBox3->setValue(OrdNum[(Pages-1)*4 + 2]);
        }

    }
    else
    {
        ui->img1->setPixmap(Dishes[(Pages-1)*4 + 0].pix);
        ui->name1->setText(Dishes[(Pages-1)*4 + 0].name);
        ui->spinBox1->setValue(OrdNum[(Pages-1)*4 + 0]);

        ui->img2->setPixmap(Dishes[(Pages-1)*4 + 1].pix);
        ui->name2->setText(Dishes[(Pages-1)*4 + 1].name);
        ui->spinBox2->setValue(OrdNum[(Pages-1)*4 + 1]);

        ui->img3->setPixmap(Dishes[(Pages-1)*4 + 2].pix);
        ui->name3->setText(Dishes[(Pages-1)*4 + 2].name);
        ui->spinBox3->setValue(OrdNum[(Pages-1)*4 + 2]);

        ui->img4->setPixmap(Dishes[(Pages-1)*4 + 3].pix);
        ui->name4->setText(Dishes[(Pages-1)*4 + 3].name);
        ui->spinBox4->setValue(OrdNum[(Pages-1)*4 + 3]);
    }
    ui->Pages->setText(QString(R"(%1 / %2 页)").arg(Pages).arg(MaxPages));

}


void MainWindow::on_SenButton_clicked()
{
    int i = DishNum % 4;
    if(Pages == MaxPages && i !=0)
    {
        OrdNum[(Pages-1)*4 + 0] = ui->spinBox1->value();
        if(i>=2)
        {
            OrdNum[(Pages-1)*4 + 1] = ui->spinBox2->value();
        }

        if(i>=3)
        {
            OrdNum[(Pages-1)*4 + 2] = ui->spinBox3->value();
        }
    }
    else
    {
        OrdNum[(Pages-1)*4 + 0] = ui->spinBox1->value();
        OrdNum[(Pages-1)*4 + 1] = ui->spinBox2->value();
        OrdNum[(Pages-1)*4 + 2] = ui->spinBox3->value();
        OrdNum[(Pages-1)*4 + 3] = ui->spinBox4->value();
    }

    for(int j=0;j<DishNum;j++)
    {
        if(OrdNumList.contains(j)==1)
        {
            if(OrdNum[j]!=0)OrdNumList.insert(j,OrdNum[j]);
            else OrdNumList.remove(j);
        }
        else
        {
            if(OrdNum[j]!=0)
            {
                OrdNumList.insert(j,OrdNum[j]);
            }
        }

    }

    if(OrdNumList.size() == 0)
    {
        QMessageBox::information(this,"corre","No dishes selected");
        return;
    }

    //QString SendHostOrder;
    QString SendchildwiOrder;
    SendchildwiOrder.clear();
    SendHostOrder.clear();
    QMapIterator<int, int> iterator(OrdNumList);
    while (iterator.hasNext()) {
        iterator.next();
        SendHostOrder.append(QString::number(iterator.key()) + ":" + QString::number(iterator.value()));
        SendchildwiOrder.append(Dishes[iterator.key()].name + ":" + QString::number(iterator.value()) + "  copies  ");
        if(iterator.hasNext())
        {
            SendHostOrder.append("/");
            SendchildwiOrder.append(",");
        }
    }
    ui->textBrowser->append(SendHostOrder);
    ui->textBrowser->append(SendchildwiOrder);

    senwi = new SendOrderWindow;
    senwi->show();

    connect(this,SIGNAL(SendOrderTChild(QString)),senwi,SLOT(ReceiveOrder(QString)));
    emit SendOrderTChild(SendchildwiOrder);

    connect(senwi,SIGNAL(SendBool(bool)),this,SLOT(ReceiveChild(bool)));
//    QMapIterator<QString, int> iterator(map);
//        while (iterator.hasNext()) {
//            iterator.next();
//            qDebug() << iterator.key() << ":" << iterator.value();
//        }



//    QString str1,str2,str3,str4,str;
//    str1.setNum(ui->spinBox1->value());
//    str2.setNum(ui->spinBox2->value());
//    str3.setNum(ui->spinBox3->value());
//    str4.setNum(ui->spinBox4->value());
//    str = str1 + '/' + str2 + '/' + str3 + '/' + str4;
//    ui->textBrowser->append(str);
//    ClientPub(MeTopic,str);
}

void MainWindow::on_PrePagesButton_clicked()
{
    OrdNum_Page();
   if(Pages <= MaxPages && Pages >1)
   {
       Pages--;
   }
    LoadData();
}

void MainWindow::on_NexPagesButton_clicked()
{
    OrdNum_Page();
    if(Pages < MaxPages)
    {
        Pages++;
    }
    LoadData();
}

void MainWindow::OrdNum_Page()
{
    int i = DishNum % 4;
    if(Pages == MaxPages && i !=0)
    {
        OrdNum[(Pages-1)*4 + 0] = ui->spinBox1->value();
        if(i>=2)
        {
            OrdNum[(Pages-1)*4 + 1] = ui->spinBox2->value();
        }

        if(i>=3)
        {
            OrdNum[(Pages-1)*4 + 2] = ui->spinBox3->value();
        }
    }
    else
    {
        OrdNum[(Pages-1)*4 + 0] = ui->spinBox1->value();
        OrdNum[(Pages-1)*4 + 1] = ui->spinBox2->value();
        OrdNum[(Pages-1)*4 + 2] = ui->spinBox3->value();
        OrdNum[(Pages-1)*4 + 3] = ui->spinBox4->value();
    }
    ui->spinBox1->setValue(0);
    ui->spinBox2->setValue(0);
    ui->spinBox3->setValue(0);
    ui->spinBox4->setValue(0);
}

void MainWindow::ReceiveChild(bool i)
{
    delete senwi;
    if(i == 1)
    {
        ClientPub(MeTopic,SendHostOrder);
    }
}
