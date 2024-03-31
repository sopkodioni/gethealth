#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include <string>
using namespace std;

class Appointment
{
private:
    int id;
    string selectedDoctor;
    string selectedDate;
    string selectedTime;
public:
    Appointment(int id, string selectedDoctor, string selectedDate, string selectedTime);
    int GetId();
    string GetSelectedDoctor();
    string GetSelectedDate();
    string GetSelectedTime();
};

#endif // APPOINTMENT_H
