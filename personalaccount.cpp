#include "personalaccount.h"
#include "ui_personalaccount.h"

#include "mainwindow.h"
#include "myAppointments.h"
#include "usersdata.h"

personalAccount::personalAccount(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::personalAccount)
{
    ui->setupUi(this);

    UsersData usersData;
    QJsonArray usersList = usersData.getArrayUsersData();

    for(int i = 0; i < usersList.size(); i++){
        QJsonObject user = usersList[i].toObject();
        if(user.contains("current")){
            ui->name->setText(user.value("name").toString());
            ui->surname->setText(user.value("surname").toString());
            ui->patronymic->setText(user.value("patronymic").toString());
            ui->gender->setText(user.value("gender").toString());
            ui->phoneNumber->setText(user.value("phoneNumber").toString());
        }
    }


}

personalAccount::~personalAccount()
{
    delete ui;
}

void personalAccount::on_exitButton_clicked()
{
    QApplication::quit();
}


void personalAccount::on_editButton_clicked()
{
    MyAppointments s;
    s.show();
    s.exec();
}

