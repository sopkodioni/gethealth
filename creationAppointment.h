#ifndef CREATIONAPPOINTMENT_H
#define CREATIONAPPOINTMENT_H

#include <QDialog>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>

using namespace std;


namespace Ui {
class CreationAppointment;
}

class CreationAppointment : public QDialog
{
    Q_OBJECT

public:
    explicit CreationAppointment(QWidget *parent = nullptr);
    ~CreationAppointment();

    QJsonArray getDoctors();

private:
    Ui::CreationAppointment *ui;
};

#endif // CREATIONAPPOINTMENT_H
