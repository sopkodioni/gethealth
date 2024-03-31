#include "appointment.h"
#include "ui_appointment.h"

Appointment::Appointment(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Appointment)
{
    ui->setupUi(this);
    ui->date->setPlaceholderText("Дата прийому");
    ui->time->setPlaceholderText("Час прийому");
}

Appointment::~Appointment()
{
    delete ui;
}
