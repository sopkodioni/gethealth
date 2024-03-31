#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include <QUuid>
#include <string>
using namespace std;

class Appointment
{
private:
    string id = QString(QUuid::createUuid().toByteArray()).toStdString();
    string selectedDoctor;
    string selectedDate;
    string selectedTime;

public:
    Appointment(string selectedDoctor, string selectedDate, string selectedTime);
    string GetId();
    string GetSelectedDoctor();
    string GetSelectedDate();
    string GetSelectedTime();
};

#endif // APPOINTMENT_H
