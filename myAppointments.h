#ifndef MYAPPOINTMENTS_H
#define MYAPPOINTMENTS_H

#include <QDialog>

namespace Ui {
class myAppointments;
}

class myAppointments : public QDialog
{
    Q_OBJECT

public:
    explicit myAppointments(QWidget *parent = nullptr);
    ~myAppointments();

private slots:
    void on_delete_1_clicked();

    void on_pushButton_pressed();

    void on_pushButton_2_pressed();

    void on_pushButton_3_pressed();

    void on_pushButton_4_pressed();

    void on_pushButton_released();

    void on_pushButton_2_released();

    void on_pushButton_3_released();

    void on_pushButton_4_released();

private:
    Ui::myAppointments *ui;
};

#endif // MYAPPOINTMENTS_H
