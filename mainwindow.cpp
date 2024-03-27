#include "mainwindow.h"
#include "ui_mainwindow.h"

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
