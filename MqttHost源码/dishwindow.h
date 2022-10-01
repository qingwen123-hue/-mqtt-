#ifndef DISHWINDOW_H
#define DISHWINDOW_H

#include <QMainWindow>
#include <QBuffer>
#include <QSqlDatabase>
#include <QSqlQuery>


namespace Ui {
class Dishwindow;
}

class Dishwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dishwindow(QWidget *parent = nullptr);
    ~Dishwindow();

private:
    Ui::Dishwindow *ui;
};

#endif // DISHWINDOW_H
