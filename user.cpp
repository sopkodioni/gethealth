#include "user.h"
#include <QDebug>

User::User
(
    string name,
    string surname,
    string patronymic,
    string dateOfBirth,
    string numberPhone,
    string password,
    string gender
){
    this->name = name;
    this->surname = surname;
    this->patronymic = patronymic;
    this->dateOfBirth = dateOfBirth;
    this->numberPhone = numberPhone;
    this->gender = gender;
    this->password = password;
    this->appointments = vector<Appointment>();
}

string User::GetId(){
    return this->id;
}

string User::GetName(){
    return this->name;
}

void User::SetName(string name){
    this->name = name;
}

string User::GetSurname(){
    return this->surname;
}

void User::SetSurname(string surname){
    this->surname = surname;
}

string User::GetPatronymic(){
    return this->patronymic;
}

void User::SetPatronymic(string patronymic){
    this->patronymic = patronymic;
}

string User::GetDateOfBirth(){
    return this->dateOfBirth;
}

void User::SetDateOfBirth(string dateOfBirth){
    this->dateOfBirth = dateOfBirth;
}

string User::GetNumberPhone(){
    return this->numberPhone;
}

void User::SetNumberPhone(string numberPhone){
    this->numberPhone = numberPhone;
}

string User::GetPassword(){
    return this->password;
}

void User::SetPassword(string password){
    this->password = password;
}

string User::GetGender(){
    return this->gender;
}

void User::SetGender(string gender){
    this->gender = gender;
}

void User::newAppointment(Appointment appointment){
    this->appointments.push_back(appointment);
}

vector<Appointment> User::GetAppointments(){
    return this->appointments;
}
