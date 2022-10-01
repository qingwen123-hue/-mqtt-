#include "deletedishwindow.h"
#include "ui_deletedishwindow.h"

DeleteDishWindow::DeleteDishWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DeleteDishWindow)
{
    ui->setupUi(this);
}

DeleteDishWindow::~DeleteDishWindow()
{
    delete ui;
}

void DeleteDishWindow::on_pushButton_clicked()
{
    emit SendDeleteDish(ui->comboBox->currentText());
}

void DeleteDishWindow::receiveData(QStringList names)
{
    for(int j=0;j<names.size();j++)
    {
        ui->comboBox->addItem(names[j]);
    }
}

