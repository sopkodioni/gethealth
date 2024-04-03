#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>
#include <string>
#include "usersdata.h"

namespace Ui {
class Registration;
}

class Registration : public QDialog
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();
    bool UserRegistration();
    bool isValidForm();
    bool isEmptyForm();
    bool isValidNumberPhone();
    bool isValidPassword();
    bool isUserExists(UsersData &userData, string &inputNumberPhone);


private slots:
    void on_exit_clicked();

    void on_sendRegistr_clicked();

private:
    Ui::Registration *ui;
};

#endif // REGISTRATION_H
