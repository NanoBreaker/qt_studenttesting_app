#include "studentwindow.h"
#include "ui_studentwindow.h"
#include "testpassing.h"

#include "test.h"
#include "question.h"

#include <QVector>
#include <QTime>
#include <QDate>

QVector<Test> vectorOfTests_lol;

TestPassing * passthetest;

int selectedTestIndex_lol;

StudentWindow::StudentWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentWindow)
{
    ui->setupUi(this);

    passthetest = new TestPassing();

    QPalette p = ui->userFIO_lineEdit->palette();
    p.setColor(QPalette::Base, Qt::green);
    ui->userFIO_lineEdit->setPalette(p);
    ui->userFIO_lineEdit->setText("Драгуцан Егор Иванович ПИ3-1");

    Test first_test;
    first_test.lecturerInformation = "Поламарчук Лариса Николаевна";
    first_test.testInformation = "Тест на тему множества\nИнформация о тесте . . .";
    first_test.amountOfQuestions = 5;
    first_test.creationDate = QDate(2017,01,10);
    first_test.passingTime = QTime(0, 10, 0, 0);
    vectorOfTests_lol.push_back(first_test);
}

StudentWindow::~StudentWindow()
{
    delete ui;
}

void StudentWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1) ui->groupBox_2->setEnabled(1);
    else ui->groupBox_2->setEnabled(0);
}

void StudentWindow::on_finishSession_pushButton_clicked()
{
    this->setVisible(false);
    emit studentWindowIsClosedSend();
}

void StudentWindow::on_treeWidget_doubleClicked(const QModelIndex &index)
{
    if(index.row() <= vectorOfTests_lol.size())
    {
        ui->testInformation_textEdit->setText(vectorOfTests_lol[index.row()].testInformation);
        ui->numberOfQuestions_lineEdit->setText(QString::number(vectorOfTests_lol[index.row()].amountOfQuestions));
        ui->lecturer_lineEdit->setText(vectorOfTests_lol[index.row()].lecturerInformation);
        ui->testTime_lineEdit->setText(vectorOfTests_lol[index.row()].passingTime.toString());
        selectedTestIndex_lol = index.row();
    }
}

void StudentWindow::on_pushButton_clicked()
{
    passthetest->show();
}
