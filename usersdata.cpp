#include "usersdata.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>

UsersData::UsersData() {}

QJsonArray UsersData::getArrayData(){
    QFile jsonUsers("users.json");
    if (!jsonUsers.open(QIODevice::ReadOnly)){
        qWarning("Couldn't open file.");
    }

    QByteArray usersData = jsonUsers.readAll();

    QJsonDocument jsonDocument = QJsonDocument::fromJson(usersData);

    QJsonArray arrayUsersData = jsonDocument.array();

    return arrayUsersData;
}
