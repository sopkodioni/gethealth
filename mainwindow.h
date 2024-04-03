#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLineEdit>
#include <QMainWindow>

#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void checkAuthorization(const QString &phoneNumber, const QString &password);

    bool isPhoneNumberValid(const QString &phoneNumber);

    bool isEmptyField(const QString &text);

    void clearFieldHighlight(QLineEdit *lineEdit);
    void setLineEditErrorStyle(QLineEdit *lineEdit);
private slots:
    void on_pushButton_clicked();

    void on_comeInButton_clicked();

    void openPersonalAccount();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
