#include "creationAppointment.h"
#include "ui_creationAppointment.h"

CreationAppointment::CreationAppointment(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreationAppointment)
{
    ui->setupUi(this);
    ui->date->setPlaceholderText("Дата прийому");
    ui->time->setPlaceholderText("Час прийому");
}

CreationAppointment::~CreationAppointment()
{
    delete ui;
}
