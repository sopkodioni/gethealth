#include "usersdata.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QDebug>

UsersData::UsersData() {
    QFile jsonUsers("users.json");
    if (!jsonUsers.open(QIODevice::ReadOnly)){
        qWarning("Couldn't open file.");
    }
    QByteArray usersData = jsonUsers.readAll();
    QJsonDocument jsonDocument = QJsonDocument::fromJson(usersData);

    this->arrayUsersData = jsonDocument.array();
}

QJsonArray UsersData::getArrayUsersData(){
    return this->arrayUsersData;
}



