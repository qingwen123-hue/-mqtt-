#ifndef ADDDHISWINDOW_H
#define ADDDHISWINDOW_H

#include <QMainWindow>

namespace Ui {
class AddDhisWindow;
}

class AddDhisWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddDhisWindow(QWidget *parent = nullptr);
    ~AddDhisWindow();

signals:
    void SendData(QString name,QString img_file);

private slots:
    void on_ImgFileButton_clicked();

    void on_OKButton_clicked();

    void on_NoButton_clicked();

private:
    Ui::AddDhisWindow *ui;
    QString dish_name;
    QString imgfile;
};

#endif // ADDDHISWINDOW_H
