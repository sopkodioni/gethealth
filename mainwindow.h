#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>

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

    void setLineEditErrorStyle(QLineEdit *lineEdit);
    void checkAuthorization(const QString &phoneNumber,
                            const QString &password,
                            QLineEdit *loginField,
                            QLineEdit *passwordField);

private slots:
    void on_pushButton_clicked();

    void on_comeInButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
