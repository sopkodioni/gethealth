#ifndef CREATIONAPPOINTMENT_H
#define CREATIONAPPOINTMENT_H

#include <QDialog>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
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

private slots:
    void on_ButtonAppoint_clicked();

    void on_ButtonBack_clicked();

private:
    Ui::CreationAppointment *ui;
};

#endif // CREATIONAPPOINTMENT_H
