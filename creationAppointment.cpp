#include "creationAppointment.h"
#include "ui_creationAppointment.h"

CreationAppointment::CreationAppointment(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreationAppointment)
{
    ui->setupUi(this);

    foreach (const QJsonValue & value, this->getDoctors()){
        QString doctor = value.toString();
        ui->doctorsList->addItem(doctor);
    }
}

CreationAppointment::~CreationAppointment()
{
    delete ui;
}

QJsonArray CreationAppointment::getDoctors(){
    QFile jsonDoctors("doctors.json");
    if (!jsonDoctors.open(QIODevice::ReadOnly)){
        qWarning("Couldn't open file.");
    }

    QByteArray doctorsList = jsonDoctors.readAll();
    QJsonDocument jsonDocument = QJsonDocument::fromJson(doctorsList);

    return jsonDocument.array();
}
