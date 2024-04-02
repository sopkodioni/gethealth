#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "registration.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include <QIntValidator>
#include <QRegularExpression>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->loginField->setPlaceholderText("Логін (ex: 098xxxxxxx)");
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

void MainWindow::checkAuthorization(const QString &phoneNumber,
                                    const QString &password)
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

    for (auto it = jsonObject.begin(); it != jsonObject.end(); ++it) {
        QJsonObject user = it.value().toObject();
        if (user.value("phoneNumber").toString() == phoneNumber) {
            if (user.value("password").toString() == password) {
                qDebug() << "Авторизация успешна!";
                return;
            } else {
                QMessageBox::critical(nullptr, "Error", "Невірний пароль");
                return;
            }
        }
    }

    // Если пользователь не найден
    QMessageBox::critical(nullptr, "Error", "Такого користувача немає");
}

bool MainWindow::isPhoneNumberValid(const QString &phoneNumber)
{
    QString phoneRegex = "^0\\d{9}$";
    QRegularExpression regex(phoneRegex);
    return regex.match(phoneNumber).hasMatch();
}

bool MainWindow::isEmptyField(const QString &text)
{
    return text.isEmpty();
}

void MainWindow::clearFieldHighlight(QLineEdit *lineEdit)
{
    lineEdit->setStyleSheet("border-radius: 20px;"
                            "background-color:#F2EFEF;"
                            "padding: 8px 18px;");
}

void MainWindow::setLineEditErrorStyle(QLineEdit *lineEdit)
{
    lineEdit->setStyleSheet("border: 1px solid red;"
                            "border-radius: 20px;"
                            "background-color:#F2EFEF;"
                            "padding: 8px 18px;");
}

void MainWindow::on_comeInButton_clicked()
{
    QString phoneNumber = ui->loginField->text();
    QString password = ui->passwordField->text();

    if (isEmptyField(phoneNumber)) {
        QMessageBox::critical(nullptr, "Error", "Поле 'Логін' не може бути порожнім");
        setLineEditErrorStyle(ui->loginField);
        return;
    }

    if (isEmptyField(password)) {
        QMessageBox::critical(nullptr, "Error", "Поле 'Пароль' не може бути порожнім");
        setLineEditErrorStyle(ui->passwordField);
        return;
    }

    // Если поля не пустые, убираем подсветку ошибки (если есть)
    clearFieldHighlight(ui->loginField);
    clearFieldHighlight(ui->passwordField);

    if (!isPhoneNumberValid(phoneNumber)) {
        QMessageBox::critical(nullptr, "Error", "Номер телефону повинен містити 10 цифр");
        setLineEditErrorStyle(ui->loginField);
        return;
    }

    checkAuthorization(phoneNumber, password);
}
