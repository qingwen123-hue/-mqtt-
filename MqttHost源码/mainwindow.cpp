#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QBuffer>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFileDialog>
#include <string.h>
extern QSqlQuery query;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //DataLoad();

    ui->textBrowser->close();

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("dish.db");

    //打开数据库
    if(db.open())
    {
        qDebug()<<"open success";
    }

    const QString sql=R"(
                                CREATE TABLE IF NOT EXISTS  dish (
                                name char[10],
                                img BLOB
                              );)";

    QSqlQuery query(db);

    if(query.exec(sql)){
        ui->textBrowser_2->append("连接数据库成功");
    }


    DishNum = 0;


    if(query.exec(QString(R"(SELECT name,img FROM dish;)")))
    {
        ui->textBrowser_2->append("读取数据中。。。");
    }
    while(query.next()){
        Dishes[DishNum].grade = DishNum;
        Dishes[DishNum].name = query.value(0).toString();
        QString imgStr=query.value(1).toString();
        QByteArray imgData = QByteArray::fromBase64(imgStr.toUtf8());//字符串转图像数据
        Dishes[DishNum].pix.loadFromData(imgData);
        DishNum++;

    }

    ui->textBrowser_2->append(QString(R"(数据读取完成，共%1个菜品)").arg(DishNum));


    client = new QMqttClient;

    client->setHostname("192.168.1.201");
    client->setPort(1883);
    client->setUsername("ykl");
    client->setPassword("123456");

    connect(client,&QMqttClient::connected,this,&MainWindow::connectSuccessSlot);


    Pages = 1;
    ui->Pages->setText(QString(R"(%1 / %2 页)").arg(Pages).arg(MaxPages));
    DataReLoad();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_connectButton_clicked()
{
    client->connectToHost();
}

void MainWindow::connectSuccessSlot()
{
    //QMessageBox::information(this,"连接提示","连接成功");
    ui->textBrowser->append("连接服务器成功");
    ui->textBrowser_2->append("连接服务器成功");
    client->subscribe(TheMotif);
    ui->textBrowser->append("订阅"+TheMotif+"主题成功");
    connect(client,&QMqttClient::messageReceived,this,&MainWindow::recxMessageSlot);
    connect(client,&QMqttClient::disconnected,[this]()
    {
        QMessageBox::information(this,"连接提示","服务器断开");
    });
}

void MainWindow::recxMessageSlot(const QByteArray &ba,const QMqttTopicName &topic)
{
    QString str = QString(ba);
    ui->textBrowser->append("接收到  "+ topic.name() + ':' + str);
    if(topic.name() == TheMotif)
    {
        if(TocipList.contains(str)==1)
        {
            ui->textBrowser->append("已订阅"+str+"主题");
            TocipList.insert(str,0);
            QByteArray ba1;
            ba1.append("OK");
            client->publish(str+"_t",ba1);
            return;
        }
        TocipList.insert(str,0);
        client->subscribe(str);
        ui->textBrowser->append("订阅"+str+"主题成功");
        ui->textBrowser_2->append(str+"机器上线");
        QByteArray ba1;
        ba1.append("OK");
        client->publish(str+"_t",ba1);
    }
    else if(TocipList.contains(topic.name())==1)
    {

        int i=TocipList.find(topic.name()).value();
        QByteArray ba;
        if(TocipList.find(topic.name()).value() == DishNum)
        {
            if(str == "Offline")
            {
                ui->textBrowser->append(topic.name() + "已下线");
                ui->textBrowser_2->append(str+"机器下线");
                client->unsubscribe(topic.name() + "_t");
                TocipList.remove(topic.name());
                ui->textBrowser->append("断开与"+topic.name()+"主题连接");
            }
            else
            {
                QString str_buf;
                str_buf = (QString)ba;
                ui->textBrowser->append(str);
                OrderList = str.split('/');
                QString splitstr,tt;
                for(int i=0;i<OrderList.size();i++){
                    splitstr = OrderList[i];
                    //cout<<i<<" "<<splitstr.toStdString()<<endl;
                    QString str1;
                    str1.setNum(i);
                    //ui->textBrowser->append(str1 + ':' + splitstr);
                    QStringList MMList = splitstr.split(':');
                    tt += Dishes[MMList[0].toInt()].name + " " + MMList[1] + "份";
                    if(i+1!=OrderList.size())tt+=',';
                }
                ui->textBrowser_2->append(topic.name()+"的订单:"+tt);
            }
        }
        else
        {
            if(str == "OK_t")
            {
                ba.setNum(Dishes[i].grade);
                client->publish(topic.name()+"_t",ba);
            }
            else if(str == "grade_t")
            {
                //ba.append(Dishes[i].name);
                ba = Dishes[i].name.toUtf8();
                client->publish(topic.name()+"_t",ba);
            }
            else if(str == "name_t")
            {
                ba=ImgToQByteArray(Dishes[i].pix);
                client->publish(topic.name()+"_t",ba);
            }
            else if(str == "img_t")
            {
                TocipList.insert(topic.name(),TocipList.find(topic.name()).value() + 1);
                int b = TocipList.find(topic.name()).value();
                ba.setNum(b);
                ui->textBrowser->append(ba);
                if(TocipList.find(topic.name()).value() == DishNum)
                {
                    client->publish(topic.name()+"_t","TransferComplete");
                }
                else
                {
                    client->publish(topic.name()+"_t","TransferIncomplete");
                }

            }
        }


    }
}



QByteArray MainWindow::ImgToQByteArray(QPixmap pixmap)
{
    QByteArray pixArray;
    QBuffer buf_IB;
    if(buf_IB.open(QIODevice::WriteOnly))
    {
        pixmap.save(&buf_IB,"JPG");
        pixArray.append(buf_IB.data());
        buf_IB.close();
    }
    return pixArray;
}

void MainWindow::DataReLoad()
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

        if(i>=2)
        {
            ui->img2->setPixmap(Dishes[(Pages-1)*4 + 1].pix);
            ui->name2->setText(Dishes[(Pages-1)*4 + 1].name);
        }

        if(i>=3)
        {
            ui->img3->setPixmap(Dishes[(Pages-1)*4 + 2].pix);
            ui->name3->setText(Dishes[(Pages-1)*4 + 2].name);
        }

    }
    else
    {
        ui->img1->setPixmap(Dishes[(Pages-1)*4 + 0].pix);
        ui->name1->setText(Dishes[(Pages-1)*4 + 0].name);

        ui->img2->setPixmap(Dishes[(Pages-1)*4 + 1].pix);
        ui->name2->setText(Dishes[(Pages-1)*4 + 1].name);

        ui->img3->setPixmap(Dishes[(Pages-1)*4 + 2].pix);
        ui->name3->setText(Dishes[(Pages-1)*4 + 2].name);

        ui->img4->setPixmap(Dishes[(Pages-1)*4 + 3].pix);
        ui->name4->setText(Dishes[(Pages-1)*4 + 3].name);
    }
    ui->Pages->setText(QString(R"(%1 / %2 页)").arg(Pages).arg(MaxPages));

}


QString MainWindow::ImgToQString(QPixmap pixmap)
{
    QByteArray pixArray;
    QBuffer buf_IB;
    if(buf_IB.open(QIODevice::WriteOnly))
    {
        pixmap.save(&buf_IB,"JPG");
        pixArray.append(buf_IB.data());
        buf_IB.close();
    }
    QString imgStr = pixArray.toBase64();
    return imgStr;
}




void MainWindow::on_AddDishButton_clicked()
{
    addwi =new AddDhisWindow;
    addwi->show();
    connect(addwi,SIGNAL(SendData(QString,QString)),this,SLOT(ReceiveData(QString,QString)));
//    QString dir = QFileDialog::getOpenFileName(
//                    this,
//                    tr("选择文件"),
//                    "",
//                    "(*.img);;All files(*.*)");
//    ui->textBrowser->append(dir);
}

void MainWindow::ReceiveData(QString name,QString img_file)
{
    ui->textBrowser->append(name);
    ui->textBrowser->append(img_file);
    delete addwi;
    if(name != "" && img_file != "")
    {
        QPixmap Pix;
        Pix.load(img_file);
        Pix = Pix.scaled(200,200,Qt::IgnoreAspectRatio);
        QSqlQuery query;

        if(query.exec(QString(R"(INSERT INTO dish(name,img) VALUES('%1','%2');)").arg(name).arg(ImgToQString(Pix))))
        {
            ui->textBrowser->append("add data success");
            ui->textBrowser_2->append("add data success");
        }

        DishNum = 0;

        if(query.exec(QString(R"(SELECT name,img FROM dish;)")))
        {
            ui->textBrowser->append("重新读取数据中。。。");
            //ui->textBrowser_2->append("重新读取数据中。。。");
        }
        while(query.next()){
            Dishes[DishNum].grade = DishNum;
            Dishes[DishNum].name = query.value(0).toString();
            QString imgStr=query.value(1).toString();
            QByteArray imgData = QByteArray::fromBase64(imgStr.toUtf8());//字符串转图像数据
            Dishes[DishNum].pix.loadFromData(imgData);
            DishNum++;
        }

        ui->textBrowser->append(QString(R"(数据读取完成，共%1个菜品)").arg(DishNum));
        //ui->textBrowser_2->append(QString(R"(数据读取完成，共%1个菜品)").arg(DishNum));
        DataReLoad();
    }

}


void MainWindow::on_DeleteDishButton_clicked()
{
    delwi = new DeleteDishWindow;
    delwi->show();
    connect(this,SIGNAL(SendDishDel(QStringList)),delwi,SLOT(receiveData(QStringList)));
    connect(delwi,SIGNAL(SendDeleteDish(QString)),this,SLOT(DeleteDish(QString)));
    QStringList names;
    for(int i=0;i<DishNum;i++)
    {
        names<<Dishes[i].name;
    }
    emit SendDishDel(names);
}

void MainWindow::DeleteDish(QString name)
{
    ui->textBrowser->append(name);
    delete delwi;
    QSqlQuery query;
    if(query.exec(QString(R"(DELETE FROM dish WHERE name='%1';)").arg(name)))
    {
       ui->textBrowser->append("delete data success");
       ui->textBrowser_2->append("delete data success");
    }
    DishNum = 0;

    if(query.exec(QString(R"(SELECT name,img FROM dish;)")))
    {
        ui->textBrowser->append("重新读取数据中。。。");
    }
    while(query.next()){
        Dishes[DishNum].grade = DishNum;
        Dishes[DishNum].name = query.value(0).toString();
        QString imgStr=query.value(1).toString();
        QByteArray imgData = QByteArray::fromBase64(imgStr.toUtf8());//字符串转图像数据
        Dishes[DishNum].pix.loadFromData(imgData);
        DishNum++;
    }

    ui->textBrowser->append(QString(R"(数据读取完成，共%1个菜品)").arg(DishNum));
    DataReLoad();
}

void MainWindow::on_PrePagesButton_clicked()
{
    if(Pages <= MaxPages && Pages >1)
    {
        Pages--;
    }
     DataReLoad();
}


void MainWindow::on_NexPagesButton_clicked()
{
    if(Pages < MaxPages)
    {
        Pages++;
    }
    DataReLoad();
}

