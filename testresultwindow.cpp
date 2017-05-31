#include "testresultwindow.h"
#include "ui_testresultwindow.h"

#include "QMessageBox"
#include "QSqlDatabase"
#include "QtSql"
#include "QDebug"

QSqlQueryModel *model;

TestResultWindow::TestResultWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestResultWindow)
{
    ui->setupUi(this);

    model = new QSqlQueryModel();
}

TestResultWindow::~TestResultWindow()
{
    delete ui;
}

void TestResultWindow::on_comboBox_currentIndexChanged(int index)
{
    model->setQuery("SELECT STUDENT_ID as 'ИД Студента', FULL_NAME as 'ФИО Студента', QUESTION_1 as 'Вопрос N1', QUESTION_2 as 'Вопрос N2', QUESTION_3 as 'Вопрос N3', QUESTION_4 as 'Вопрос N4', QUESTION_5 as 'Вопрос N5', RESULT as 'Результат тестирования' FROM tests_results");
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    QPalette p = ui->tableView->palette();
    p.setColor(QPalette::Base, Qt::yellow);
    ui->tableView->horizontalHeader()->setBackgroundRole(QPalette::Dark);
}
