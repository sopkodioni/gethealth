#ifndef PERSONALACCOUNT_H
#define PERSONALACCOUNT_H

#include <QDialog>

namespace Ui {
class personalAccount;
}

class personalAccount : public QDialog
{
    Q_OBJECT

public:
    explicit personalAccount(QWidget *parent = nullptr);
    ~personalAccount();

private:
    Ui::personalAccount *ui;
};

#endif // PERSONALACCOUNT_H
