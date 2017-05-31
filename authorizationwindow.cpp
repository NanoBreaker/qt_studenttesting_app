#include "authorizationwindow.h"
#include "ui_authorizationwindow.h"
#include "teacherwindow.h"
#include "studentwindow.h"

#include "QMessageBox"
#include "QSqlDatabase"
#include "QtSql"
#include "QDebug"

TeacherWindow * teacherWindow;
StudentWindow * studentWindow;

AuthorizationWindow::AuthorizationWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AuthorizationWindow)
{
    ui->setupUi(this);

    teacherWindow = new TeacherWindow();
    studentWindow = new StudentWindow();

    //signals & slots
    connect(teacherWindow, SIGNAL(teacherWindowIsClosedSend()), this, SLOT(teacherWindowIsClosedRecived()));
    connect(studentWindow, SIGNAL(studentWindowIsClosedSend()), this, SLOT(studentWindowIsClosedRecived()));

    //establishing connection
    dataBase = QSqlDatabase::addDatabase("QMYSQL");
    QString hostName_string = "127.0.0.1";
    QString dataBaseName_string = "student_testing_database";
    QString userName_string = "root";
    QString password_string = "";
    QString port_string = "3306";

    bool isSuccessful;
    int port_int = port_string.toInt(&isSuccessful, 10);

    dataBase.setHostName(hostName_string);
    dataBase.setDatabaseName(dataBaseName_string);
    dataBase.setUserName(userName_string);
    dataBase.setPassword(password_string);
    dataBase.setPort(port_int);
    dataBase.setConnectOptions();

    bool connetionEstablished = dataBase.open();

    if(connetionEstablished)
    {
        ui->connectionStatus_lineEdit->setText("СОЕДИНЕНИЕ УСТАНОВЛЕНО");
        QPalette p = ui->connectionStatus_lineEdit->palette();
        p.setColor(QPalette::Base, Qt::green);
        ui->connectionStatus_lineEdit->setPalette(p);
        ui->signInSystem_pushButton->setEnabled(true);
    }
    else
    {
        ui->connectionStatus_lineEdit->setText("СОЕДИНЕНИЕ НЕ УСТАНОВЛЕНО");
        QPalette p = ui->connectionStatus_lineEdit->palette();
        p.setColor(QPalette::Base, Qt::red);
        ui->connectionStatus_lineEdit->setPalette(p);
        ui->signInSystem_pushButton->setEnabled(false);
    }

}

AuthorizationWindow::~AuthorizationWindow()
{
    delete ui;
}

void AuthorizationWindow::on_signInSystem_pushButton_clicked()
{
    if(ui->comboBox->currentIndex() == 0)
    {
        teacherWindow->show();
    }
    else if(ui->comboBox->currentIndex() == 1)
    {
        studentWindow->show();
    }
    //this->setVisible(false);
}

void AuthorizationWindow::teacherWindowIsClosedRecived()
{
    this->setVisible(true);
}

void AuthorizationWindow::studentWindowIsClosedRecived()
{
    this->setVisible(true);
}
