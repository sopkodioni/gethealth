#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "registration.h"

#include <QFile>
#include <QIntValidator>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QRegularExpression>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->loginField->setPlaceholderText("Логін (номер телефону з '0')");
    ui->passwordField->setPlaceholderText("Пароль");
    QString phoneRegex = "^0\\d{9}$";
    ui->loginField->setValidator(
        new QRegularExpressionValidator(QRegularExpression(phoneRegex), this));
    ui->passwordField->setEchoMode(QLineEdit::Password);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Registration windowRegistration;
    windowRegistration.setModal(true);
    windowRegistration.exec();
}

void MainWindow::setLineEditErrorStyle(QLineEdit *lineEdit)
{
    lineEdit->setStyleSheet("border: 1px solid red;"
                            "border-radius: 20px;"
                            "background-color:#F2EFEF;"
                            "padding: 8px 18px;");
}

// Функция для проверки авторизации пользователя
void MainWindow::checkAuthorization(const QString &phoneNumber,
                        const QString &password,
                        QLineEdit *loginField,
                        QLineEdit *passwordField)
{

    QString jsonFilePath= "users.json";
    QFile fileWhithUsers(jsonFilePath);
    if (!fileWhithUsers.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(nullptr, "Error", "Системна помилка");
        return;
    }

    QByteArray jsonData = fileWhithUsers.readAll();
    fileWhithUsers.close();


    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
    QJsonObject jsonObject = doc.object();


    if (jsonObject.contains(phoneNumber)) {
        QJsonObject user = jsonObject.value(phoneNumber).toObject();
        if (user.value("password").toString() == password) {
            qDebug() << "Авторизация успешна!";
        } else {
            setLineEditErrorStyle(passwordField);
        }
    } else {
        setLineEditErrorStyle(loginField);
    }
}

void MainWindow::on_comeInButton_clicked()
{
    QString phoneNumber = ui->loginField->text();
    QString password = ui->passwordField->text();
    checkAuthorization(phoneNumber, password, ui->loginField, ui->passwordField);
}

