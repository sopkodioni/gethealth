#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "registration.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->loginField->setPlaceholderText("Логін");
    ui->passwordField->setPlaceholderText("Пароль");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    hide();

    Registration windowRegistration(this);
    windowRegistration.show();
    windowRegistration.exec();
}
