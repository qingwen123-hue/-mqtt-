#include "sendorderwindow.h"
#include "ui_sendorderwindow.h"

SendOrderWindow::SendOrderWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SendOrderWindow)
{
    ui->setupUi(this);
}

SendOrderWindow::~SendOrderWindow()
{
    delete ui;
}

void SendOrderWindow::ReceiveOrder(QString text)
{
    ui->label->setFixedWidth(420);
    ui->label->setText(text);
    ui->label->setWordWrap(true);
    ui->label->adjustSize();
}



void SendOrderWindow::on_confirmButton_clicked()
{
    emit SendBool(1);
}

void SendOrderWindow::on_cancelButton_clicked()
{
    emit SendBool(0);
}
