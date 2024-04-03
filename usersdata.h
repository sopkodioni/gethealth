#ifndef USERSDATA_H
#define USERSDATA_H

#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonDocument>

#include "user.h"

using namespace std;

class UsersData
{
private:
    QJsonArray arrayUsersData;
    QJsonDocument usersJsonDoc;
public:
    UsersData();
    QJsonArray& getArrayUsersData();
    void setArrayUsersData();
    void addUser(User &user);
    static void ResetUser();
};

#endif // USERSDATA_H
