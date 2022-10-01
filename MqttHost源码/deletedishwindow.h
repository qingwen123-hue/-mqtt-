#ifndef DELETEDISHWINDOW_H
#define DELETEDISHWINDOW_H

#include <QMainWindow>

namespace Ui {
class DeleteDishWindow;
}

class DeleteDishWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeleteDishWindow(QWidget *parent = nullptr);
    ~DeleteDishWindow();

private slots:
    void on_pushButton_clicked();

    void receiveData(QStringList names);

signals:
    void SendDeleteDish(QString name);

private:
    Ui::DeleteDishWindow *ui;
};

#endif // DELETEDISHWINDOW_H
