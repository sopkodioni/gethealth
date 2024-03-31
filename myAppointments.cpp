/*
    1. Берём вектор, считаем количество элементов на странице и есть ли дальше страницы
    2. Берём информацию из вектора и переписываем в лейблы
*/

#include "myAppointments.h"
#include "ui_myAppointments.h"

MyAppointments::MyAppointments(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MyAppointments)
{
    ui->setupUi(this);

}

MyAppointments::~MyAppointments()
{
    delete ui;
}

void MyAppointments::on_delete_1_clicked()
{

}


void MyAppointments::on_pushButton_pressed()
{
    QFrame *appointmentFrame = ui->appointment_1;
    appointmentFrame->setVisible(false);
}

void MyAppointments::on_pushButton_2_pressed()
{
    QFrame *appointment4Frame = ui->appointment_4;
    appointment4Frame->setFixedSize(0, 0);
    QFrame *appointment3Frame = ui->appointment_3;
    appointment3Frame->setFixedSize(0, 0);
    ui->appointments->setFixedHeight(ui->appointments->height() - (103 * 2));
}


void MyAppointments::on_pushButton_3_pressed()
{
    QFrame *appointment4Frame = ui->appointment_4;
    appointment4Frame->setFixedSize(0, 0);
    QFrame *appointment3Frame = ui->appointment_3;
    appointment3Frame->setFixedSize(0, 0);
    QFrame *appointment2Frame = ui->appointment_2;
    appointment2Frame->setFixedSize(0, 0);
    ui->appointments->setFixedHeight(ui->appointments->height() - (103 * 3));
}


void MyAppointments::on_pushButton_4_pressed()
{
    QFrame *appointment4Frame = ui->appointment_4;
    appointment4Frame->setFixedSize(0, 0);
    QFrame *appointment3Frame = ui->appointment_3;
    appointment3Frame->setFixedSize(0, 0);
    QFrame *appointment2Frame = ui->appointment_2;
    appointment2Frame->setFixedSize(0, 0);
    QFrame *appointment1Frame = ui->appointment_1;
    appointment1Frame->setFixedSize(0, 0);
    ui->appointments->setFixedHeight(ui->appointments->height() - (103 * 4));
}

void MyAppointments::on_pushButton_released()
{
    QFrame *appointmentFrame = ui->appointment_1;
    appointmentFrame->setVisible(true);
}

void MyAppointments::on_pushButton_2_released()
{
    QFrame *appointment4Frame = ui->appointment_4;
    appointment4Frame->setFixedSize(465, 80);
    QFrame *appointment3Frame = ui->appointment_3;
    appointment3Frame->setFixedSize(465, 80);
    ui->appointments->setFixedHeight(ui->appointments->height() + (103 * 2));
}

void MyAppointments::on_pushButton_3_released()
{
    QFrame *appointment4Frame = ui->appointment_4;
    appointment4Frame->setFixedSize(465, 80);
    QFrame *appointment3Frame = ui->appointment_3;
    appointment3Frame->setFixedSize(465, 80);
    QFrame *appointment2Frame = ui->appointment_2;
    appointment2Frame->setFixedSize(465, 80);
    ui->appointments->setFixedHeight(ui->appointments->height() + (103 * 3));
}

void MyAppointments::on_pushButton_4_released()
{
    QFrame *appointment4Frame = ui->appointment_4;
    appointment4Frame->setFixedSize(465, 80);
    QFrame *appointment3Frame = ui->appointment_3;
    appointment3Frame->setFixedSize(465, 80);
    QFrame *appointment2Frame = ui->appointment_2;
    appointment2Frame->setFixedSize(465, 80);
    QFrame *appointment1Frame = ui->appointment_1;
    appointment1Frame->setFixedSize(465, 80);
    ui->appointments->setFixedHeight(ui->appointments->height() + (103 * 4));
}

