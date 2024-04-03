#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "registration.h"
#include "personalaccount.h"
#include "usersdata.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include <QIntValidator>
#include <QMessageBox>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->loginField->setPlaceholderText("Логін (ex: 098XXXXXXX)");
    ui->passwordField->setPlaceholderText("Пароль");
    QString phoneRegex = "^0\\d{9}$";
    ui->loginField->setValidator(new QRegularExpressionValidator(QRegularExpression(phoneRegex), this));
    ui->loginField->setToolTip("Введіть ваш номер телефону, обов'язково починаючи з 0");
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

void MainWindow::openPersonalAccount()
{
    close();
    personalAccount personalAccountWindow;
    personalAccountWindow.exec();

}


void MainWindow::markCurrentUser(QJsonArray arrayUsersData, QJsonDocument jsonDocument, QJsonObject user, int index){
    QJsonObject currentUser = user;

    currentUser["current"] = "true";

    arrayUsersData[index] = currentUser;

    jsonDocument.setArray(arrayUsersData);

    QFile usersList("users.json");
    if (!usersList.open(QIODevice::WriteOnly)) {
        qDebug() << "Failed to open output file";
    }
    usersList.write(jsonDocument.toJson());
    usersList.close();
}

void MainWindow::checkAuthorization(const QString &phoneNumber, const QString &password)
{
    QFile jsonUsers("users.json");
    if (!jsonUsers.open(QIODevice::ReadOnly)){
        qWarning("Couldn't open file.");
    }
    QByteArray usersData = jsonUsers.readAll();
    QJsonDocument jsonDocument = QJsonDocument::fromJson(usersData);

    QJsonArray arrayUsersData = jsonDocument.array();

    for(int i = 0; i < arrayUsersData.size(); i++){
        QJsonObject user = arrayUsersData[i].toObject();

        QString inputPhoneNumber = user.value("phoneNumber").toString().trimmed();
        QString inputPassword = user.value("password").toString().trimmed();

        if (inputPhoneNumber == phoneNumber.trimmed()) {
            if (inputPassword == password.trimmed()) {
                this->markCurrentUser(arrayUsersData, jsonDocument, user, i);
                openPersonalAccount();
                return;
            }

            QMessageBox::critical(nullptr, "Error", "Невірний пароль");
            return;
        }
    }

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


