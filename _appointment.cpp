#include "_appointment.h"

Appointment::Appointment(
    string selectedDoctor,
    string selectedDate,
    string selectedTime
    )
{
    this->selectedDoctor = selectedDoctor;
    this->selectedDate = selectedDate;
    this->selectedTime = selectedTime;
}

string Appointment::GetId()
{
    return this->id;
}
string Appointment::GetSelectedDoctor()
{
    return this->selectedDoctor;
}
string Appointment::GetSelectedDate()
{
    return this->selectedDate;
}
string Appointment::GetSelectedTime()
{
    return this->selectedTime;
}
