#include "appointment.h"

Appointment::Appointment(string selectedDoctor, string selectedDate, string selectedTime ) : selectedDoctor(selectedDoctor), selectedDate(selectedDate), selectedTime(selectedTime) {}
string Appointment::GetId(){
    return this->id;
}
string Appointment::GetSelectedDoctor(){
    return this->selectedDoctor;
}
string Appointment::GetSelectedDate(){
    return this->selectedDate;
}
string Appointment::GetSelectedTime(){
    return this->selectedTime;
}
