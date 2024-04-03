#ifndef USER_H
#define USER_H
#include <appointment.h>
#include <string>
#include <vector>
#include <QUuid>

using namespace std;

class User
{
private:
    string id = QString(QUuid::createUuid().toByteArray()).toStdString();
    string name;
    string surname;
    string patronymic;
    string dateOfBirth;
    string numberPhone;
    string password;
    string gender;
    vector<Appointment> appointments;

public:
    User
    (
        string name,
        string surname,
        string patronymic,
        string dateOfBirth,
        string numberPhone,
        string password,
        string gender
    );

    string GetId();
    string GetName();
    void SetName(string name);
    string GetSurname();
    void SetSurname(string surname);
    string GetPatronymic();
    void SetPatronymic(string patronymic);
    string GetDateOfBirth();
    void SetDateOfBirth(string dateOfBirth);
    string GetNumberPhone();
    void SetNumberPhone(string numberPhone);
    string GetPassword();
    void SetPassword(string password);
    string GetGender();
    void SetGender(string gender);
    void newAppointment(Appointment appointment);
    vector<Appointment> GetAppointments();
};

#endif // USER_H
