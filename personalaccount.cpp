#include "personalaccount.h"
#include "ui_personalaccount.h"

#include "mainwindow.h"

personalAccount::personalAccount(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::personalAccount)
{
    ui->setupUi(this);
}

personalAccount::~personalAccount()
{
    delete ui;
}

void personalAccount::on_exitButton_clicked()
{
    QApplication::quit();
}

