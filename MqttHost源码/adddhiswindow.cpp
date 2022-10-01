#include "adddhiswindow.h"
#include "ui_adddhiswindow.h"
#include <QFileDialog>
#include <QMessageBox>
AddDhisWindow::AddDhisWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddDhisWindow)
{
    ui->setupUi(this);
    //this->setAttribute(Qt::WA_DeleteOnClose,true);
}

AddDhisWindow::~AddDhisWindow()
{
    delete ui;
}

void AddDhisWindow::on_ImgFileButton_clicked()
{
    QString dir = QFileDialog::getOpenFileName(
                        this,
                        tr("选择文件"),
                        "",
                        "All files(*.*)");
    ui->ImgFileEdit->setText(dir);

}


void AddDhisWindow::on_OKButton_clicked()
{
    dish_name = ui->DishNameEdit->text();
    imgfile = ui->ImgFileEdit->text();
    if(dish_name == "")
    {
        QMessageBox::information(this,"错误","名字未填写");
        return;
    }
    else if(imgfile == "")
    {
        QMessageBox::information(this,"错误","图像地址未填写");
        return;
    }
    emit SendData(dish_name,imgfile);
}


void AddDhisWindow::on_NoButton_clicked()
{
    emit SendData("","");
}

