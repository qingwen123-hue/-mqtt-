#include "dishwindow.h"
#include "ui_dishwindow.h"



Dishwindow::Dishwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dishwindow)
{
    ui->setupUi(this);
}

Dishwindow::~Dishwindow()
{
    delete ui;
}
