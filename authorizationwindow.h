#ifndef AUTHORIZATIONWINDOW_H
#define AUTHORIZATIONWINDOW_H

#include <QMainWindow>
#include "QSqlDatabase"

namespace Ui {
class AuthorizationWindow;
}

class AuthorizationWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AuthorizationWindow(QWidget *parent = 0);
    QSqlDatabase dataBase;
    ~AuthorizationWindow();

private slots:
    void on_signInSystem_pushButton_clicked();

    void teacherWindowIsClosedRecived();
    void studentWindowIsClosedRecived();

private:
    Ui::AuthorizationWindow *ui;
};

#endif // AUTHORIZATIONWINDOW_H
