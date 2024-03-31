#ifndef CREATIONAPPOINTMENT_H
#define CREATIONAPPOINTMENT_H

#include <QDialog>

namespace Ui {
class CreationAppointment;
}

class CreationAppointment : public QDialog
{
    Q_OBJECT

public:
    explicit CreationAppointment(QWidget *parent = nullptr);
    ~CreationAppointment();

private:
    Ui::CreationAppointment *ui;
};

#endif // CREATIONAPPOINTMENT_H
