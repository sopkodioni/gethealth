#ifndef MYAPPOINTMENTS_H
#define MYAPPOINTMENTS_H

#include <QDialog>
#include "usersdata.h"

namespace Ui {
class MyAppointments;
}

class MyAppointments : public QDialog
{
    Q_OBJECT

public:
    explicit MyAppointments(QWidget *parent = nullptr);
    ~MyAppointments();

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
    Ui::MyAppointments *ui;
};

#endif // MyAppointments_H
