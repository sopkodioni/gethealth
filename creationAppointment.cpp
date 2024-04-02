#include "creationAppointment.h"
#include "ui_creationAppointment.h"

CreationAppointment::CreationAppointment(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreationAppointment)
{
    ui->setupUi(this);
}

CreationAppointment::~CreationAppointment()
{
    delete ui;
}
