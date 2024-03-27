#include "registration.h"
#include "ui_registration.h"

Registration::Registration(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Registration)
{
    ui->setupUi(this);

    ui->userName->setStyleSheet("border-radius: 30px");

    ui->userName->setPlaceholderText("Ім'я");
    ui->userSurname->setPlaceholderText("Прізвище");
    ui->userPatronymic->setPlaceholderText("Побатькові");
}

Registration::~Registration()
{
    delete ui;
}
