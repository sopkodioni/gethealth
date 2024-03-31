#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "registration.h"

#include <QRegularExpression>
#include <QIntValidator>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->loginField->setPlaceholderText("Логін (номер телефону з '0')");
    ui->passwordField->setPlaceholderText("Пароль");
    QString phoneRegex = "^\\d{10}$";
    ui->loginField->setValidator(new QRegularExpressionValidator(QRegularExpression(phoneRegex), this));
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

void setLineEditErrorStyle(QLineEdit* lineEdit) {
    lineEdit->setStyleSheet("border: 1px solid red;");
}

// Функция для проверки авторизации пользователя
void checkAuthorization(const QString& phoneNumber, const QString& password, QLineEdit* loginField, QLineEdit* passwordField)
{
    // Загрузка JSON-файла с данными пользователей
    QFile fileWhithUsers("users.json");
    if (!fileWhithUsers.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(nullptr, "Error", "Системна помилка");
        return;
    }
    // Чтение JSON-документа из файла
    QByteArray jsonData = fileWhithUsers.readAll();
    fileWhithUsers.close();

    // Преобразование JSON-документа в объект
    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
    QJsonObject jsonObject = doc.object();

    // Поиск пользователя по номеру телефона
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

