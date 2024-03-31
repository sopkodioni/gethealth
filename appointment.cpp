#include "appointment.h"

Appointment::Appointment(int id, string selectedDoctor, string selectedDate, string selectedTime ) : id(id), selectedDoctor(selectedDoctor), selectedDate(selectedDate), selectedTime(selectedTime) {}
int Appointment::GetId(){
    return id;
}
string Appointment::GetSelectedDoctor(){
    return selectedDoctor;
}
string Appointment::GetSelectedDate(){
    return selectedDate;
}
string Appointment::GetSelectedTime(){
    return selectedTime;
}
