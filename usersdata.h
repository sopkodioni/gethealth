#ifndef USERSDATA_H
#define USERSDATA_H

#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>

#include "appointment.h"

using namespace std;

class UsersData
{
private:
    QJsonArray arrayUsersData;
public:
    UsersData();
    QJsonArray getArrayUsersData();
    void addUser(Appointment user);
};

#endif // USERSDATA_H
