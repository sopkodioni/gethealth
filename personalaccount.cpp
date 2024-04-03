#include "personalaccount.h"
#include "ui_personalaccount.h"

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
