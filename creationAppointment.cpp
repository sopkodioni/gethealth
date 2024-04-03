#include "creationAppointment.h"
#include "ui_creationAppointment.h"
#include "QComboBox"
#include "usersdata.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

CreationAppointment::CreationAppointment(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreationAppointment)
{
    ui->setupUi(this);

    foreach (const QJsonValue &value, this->getDoctors()) {
        QString doctor = value.toString();
        ui->doctorsList->addItem(doctor);
    }
}

CreationAppointment::~CreationAppointment()
{
    delete ui;
}

QJsonArray CreationAppointment::getDoctors()
{
    QFile jsonDoctors("doctors.json");
    if (!jsonDoctors.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open file.");
    }

    QByteArray doctorsList = jsonDoctors.readAll();
    QJsonDocument jsonDocument = QJsonDocument::fromJson(doctorsList);

    return jsonDocument.array();
}

void CreationAppointment::on_ButtonAppoint_clicked()
{
    string selectedDoctor = ui->doctorsList->currentText().toStdString();
    string selectedDate = ui->date->text().toStdString();
    string selectedTime = ui->time->text().toStdString();

    QJsonObject newAppointment;
    newAppointment["selectedDoctor"] = QJsonValue::fromVariant(QString::fromStdString(selectedDoctor));
    newAppointment["selectedDate"] = QJsonValue::fromVariant(QString::fromStdString(selectedDate));
    newAppointment["selectedTime"] = QJsonValue::fromVariant(QString::fromStdString(selectedTime));

    UsersData usersData;
    QJsonArray usersList = usersData.getArrayUsersData();

    for(int i = 0; i < usersList.size(); i++) {
        QJsonObject user = usersList[i].toObject();
        if(user.contains("current")){
            QJsonArray userAppointments = user.value("appointment").toArray();
            userAppointments.append(newAppointment);
            user.insert("appointment", userAppointments);
            usersList.removeAt(i);
            usersList.insert(i, user);
        }
    }


    QFile jsonUsers("users.json");
    if (!jsonUsers.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open file.");
    }
    QByteArray fileData = jsonUsers.readAll();
    jsonUsers.close();
    QJsonDocument jsonDocument = QJsonDocument::fromJson(fileData);

    jsonDocument.setArray(usersList);

    if (!jsonUsers.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing";
        return;
    }

    jsonUsers.write(jsonDocument.toJson());
    jsonUsers.close();

}


void CreationAppointment::on_ButtonBack_clicked()
{
    close();
}

