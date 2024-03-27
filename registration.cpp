#include <QStringList>
#include "registration.h"
#include "ui_registration.h"

Registration::Registration(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Registration)
{
    ui->setupUi(this);

    QStringList genders = (QStringList() << "Чоловіча" << "Жіноча");

    ui->userName->setPlaceholderText("Ім'я");
    ui->userSurname->setPlaceholderText("Прізвище");
    ui->userPatronymic->setPlaceholderText("Побатькові");
    ui->userNumberPhone->setPlaceholderText("Номер телефону");
    ui->userGender->setPlaceholderText("Стать");
    ui->userPassword->setPlaceholderText("Пароль");
    ui->userGender->addItems(genders);

    ui->userNumberPhone->setValidator(new QDoubleValidator(0, 100, 2, this));

}

Registration::~Registration()
{
    delete ui;
}

