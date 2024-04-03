#include "registration.h"
#include <QStringList>
#include <QJsonObject>
#include "ui_registration.h"

#include "mainwindow.h"
#include "usersdata.h"
#include "user.h"
#include <QMessageBox>

Registration::Registration(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Registration)
{
    ui->setupUi(this);

    QStringList genders = (QStringList() << "Чоловіча"
                                         << "Жіноча");

    ui->userName->setPlaceholderText("Ім'я");
    ui->userSurname->setPlaceholderText("Прізвище");
    ui->userPatronymic->setPlaceholderText("Побатькові");
    ui->userNumberPhone->setPlaceholderText("Номер телефону");
    ui->userGender->setPlaceholderText("Стать");
    ui->userPassword->setPlaceholderText("Пароль");
    ui->userGender->addItems(genders);

    ui->userNumberPhone->setValidator(new QDoubleValidator(0, 100, 2, this));

    connect(ui->exit, &QPushButton::clicked, this, &Registration::on_exit_clicked);
}

Registration::~Registration()
{
    delete ui;
}

void Registration::on_exit_clicked()
{
    close();

    MainWindow *mainWindow = qobject_cast<MainWindow *>(parent());
    if (mainWindow) {
        mainWindow->show();
    }
}

bool Registration::UserRegistration(){
    if(!this->isValidForm()){
        return false;
    }

    UsersData userData;
    string inputNumberPhone = ui->userNumberPhone->text().toStdString();

    foreach (const QJsonValue &value, userData.getArrayUsersData()) {
        QJsonObject user = value.toObject();
        QString userPhoneNumber = user.value("phoneNumber").toString();
        if (userPhoneNumber.toStdString() == inputNumberPhone) {
            QMessageBox::critical(nullptr, "Error", "Користувач за таким номером все інсує");
            return false;
        }
    }

    string inputName = ui->userName->text().toStdString();
    string inputSurname = ui->userSurname->text().toStdString();
    string inputPatronymic = ui->userPatronymic->text().toStdString();
    QString inputDateOfBirthday = ui->userDateOfBirthday->date().toString();
    string inputPassword = ui->userPassword->text().toStdString();
    string selectedGender = ui->userGender->currentText().toStdString();

    User newUser(inputName, inputSurname, inputPatronymic, inputDateOfBirthday, inputNumberPhone, inputPassword, selectedGender);
    userData.addUser(newUser);

    QMessageBox::information(nullptr, "Успіх!", "Вас зареєстровано!");
    close();

    return true;
}

bool Registration::isValidForm(){
    if(this->isEmptyForm() || !(this->isValidNumberPhone()) || !(this->isValidPassword())){
        return false;
    }

    return true;
}

bool Registration::isEmptyForm(){
    QString userName = ui->userName->text();
    QString userSurname = ui->userSurname->text();
    QString userPatronymic = ui->userPatronymic->text();
    QString userNumberPhone = ui->userNumberPhone->text();
    QString userPassword = ui->userPassword->text();

    if(userName == "" || userSurname == "" || userPatronymic == "" || userNumberPhone == "" || userPassword == ""){
        QMessageBox::critical(nullptr, "Error", "Є порожні поля!");
        return true;
    }

    return false;
}

bool Registration::isValidNumberPhone(){
    QString userNumberPhone = ui->userNumberPhone->text();

    QString phoneRegex = "^0\\d{9}$";
    QRegularExpression regex(phoneRegex);
    if(!(regex.match(userNumberPhone).hasMatch())){
        QMessageBox::critical(nullptr, "Error", "Некоректний номер телефону");
        return false;
    }

    return true;
}

bool Registration::isValidPassword(){
    QString userPassword = ui->userPassword->text();

    if(userPassword.length() < 8){
        QMessageBox::critical(nullptr, "Error", "Пароль повинен бути не меньше 8 сиволів");
        return false;
    }

    return true;
}


void Registration::on_sendRegistr_clicked()
{
    this->UserRegistration();
}

