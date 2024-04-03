#include "usersdata.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QDebug>
#include <QJsonParseError>

UsersData::UsersData() {
    this->setArrayUsersData();
}

void UsersData::setArrayUsersData(){
    QFile jsonUsers("users.json");
    if (!jsonUsers.open(QIODevice::ReadOnly)){
        qWarning("Couldn't open file.");
    }
    QByteArray usersData = jsonUsers.readAll();
    QJsonDocument jsonDocument = QJsonDocument::fromJson(usersData);

    this->arrayUsersData = jsonDocument.array();
}

QJsonArray& UsersData::getArrayUsersData(){
    return this->arrayUsersData;
}

void UsersData::addUser(User &user) {
    QFile jsonUsers("users.json");
    if (!jsonUsers.open(QIODevice::ReadOnly)){
        qWarning("Couldn't open file.");
    }
    QByteArray usersData = jsonUsers.readAll();
    jsonUsers.close();
    QJsonDocument jsonDocument = QJsonDocument::fromJson(usersData);

    QJsonObject newUser;
    newUser["id"] = QJsonValue::fromVariant(QString::fromStdString(user.GetId()));
    newUser["name"] = QJsonValue::fromVariant(QString::fromStdString(user.GetName()));
    newUser["surname"] = QJsonValue::fromVariant(QString::fromStdString(user.GetSurname()));
    newUser["patronymic"] = QJsonValue::fromVariant(QString::fromStdString(user.GetPatronymic()));
    newUser["dateOfBirthday"] = QJsonValue::fromVariant(user.GetDateOfBirth());
    newUser["gender"] = QJsonValue::fromVariant(QString::fromStdString(user.GetGender()));
    newUser["phoneNumber"] = QJsonValue::fromVariant(QString::fromStdString(user.GetNumberPhone()));
    newUser["password"] = QJsonValue::fromVariant(QString::fromStdString(user.GetPassword()));
    QJsonArray appointment;
    newUser["appointment"] = appointment;

    this->getArrayUsersData().append(newUser);

    jsonDocument.setArray(this->getArrayUsersData());

    if (!jsonUsers.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug() << "Failed to open file for writing";
        return;
    }

    jsonUsers.write(jsonDocument.toJson());
    jsonUsers.close();
}

void UsersData::ResetUser(){
    QFile jsonUsers("users.json");
    if (!jsonUsers.open(QIODevice::ReadOnly)){
        qWarning("Couldn't open file.");
    }
    QByteArray usersData = jsonUsers.readAll();
    jsonUsers.close();
    QJsonDocument jsonDocument = QJsonDocument::fromJson(usersData);

    QJsonArray users = jsonDocument.array();

    for(int i = 0; i < users.size(); i++){
        QJsonObject user = users[i].toObject();

        if(user.contains("current")){
            user.remove("current");
            users[i] = user;
        }
    }

    if (!jsonUsers.open(QIODevice::WriteOnly)) {
        qDebug() << "Failed to open output file";
        return;
    }

    jsonDocument.setArray(users);
    jsonUsers.write(jsonDocument.toJson());
    jsonUsers.close();
}



