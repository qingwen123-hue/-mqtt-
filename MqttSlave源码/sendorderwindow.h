#ifndef SENDORDERWINDOW_H
#define SENDORDERWINDOW_H

#include <QMainWindow>

namespace Ui {
class SendOrderWindow;
}

class SendOrderWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SendOrderWindow(QWidget *parent = nullptr);
    ~SendOrderWindow();

private slots:

    void ReceiveOrder(QString text);

    void on_confirmButton_clicked();

    void on_cancelButton_clicked();

signals:
    void SendBool(bool i);

private:
    Ui::SendOrderWindow *ui;
};

#endif // SENDORDERWINDOW_H
