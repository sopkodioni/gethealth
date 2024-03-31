#include "myAppointments.h"
#include "ui_myAppointments.h"

myAppointments::myAppointments(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::myAppointments)
{
    ui->setupUi(this);

}

myAppointments::~myAppointments()
{
    delete ui;
}

void myAppointments::on_delete_1_clicked()
{

}


void myAppointments::on_pushButton_pressed()
{
    QFrame *appointmentFrame = ui->appointment_1;
    appointmentFrame->setVisible(false);
}

void myAppointments::on_pushButton_2_pressed()
{
    QFrame *appointment4Frame = ui->appointment_4;
    appointment4Frame->setFixedSize(0, 0);
    QFrame *appointment3Frame = ui->appointment_3;
    appointment3Frame->setFixedSize(0, 0);
    ui->appointments->setFixedHeight(ui->appointments->height() - (103 * 2));
}


void myAppointments::on_pushButton_3_pressed()
{
    QFrame *appointment4Frame = ui->appointment_4;
    appointment4Frame->setFixedSize(0, 0);
    QFrame *appointment3Frame = ui->appointment_3;
    appointment3Frame->setFixedSize(0, 0);
    QFrame *appointment2Frame = ui->appointment_2;
    appointment2Frame->setFixedSize(0, 0);
    ui->appointments->setFixedHeight(ui->appointments->height() - (103 * 3));
}


void myAppointments::on_pushButton_4_pressed()
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

void myAppointments::on_pushButton_released()
{
    QFrame *appointmentFrame = ui->appointment_1;
    appointmentFrame->setVisible(true);
}

void myAppointments::on_pushButton_2_released()
{
    QFrame *appointment4Frame = ui->appointment_4;
    appointment4Frame->setFixedSize(465, 80);
    QFrame *appointment3Frame = ui->appointment_3;
    appointment3Frame->setFixedSize(465, 80);
    ui->appointments->setFixedHeight(ui->appointments->height() + (103 * 2));
}

void myAppointments::on_pushButton_3_released()
{
    QFrame *appointment4Frame = ui->appointment_4;
    appointment4Frame->setFixedSize(465, 80);
    QFrame *appointment3Frame = ui->appointment_3;
    appointment3Frame->setFixedSize(465, 80);
    QFrame *appointment2Frame = ui->appointment_2;
    appointment2Frame->setFixedSize(465, 80);
    ui->appointments->setFixedHeight(ui->appointments->height() + (103 * 3));
}

void myAppointments::on_pushButton_4_released()
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

