#include "addnewtestwindow.h"
#include "ui_addnewtestwindow.h"
#include "addquestionwindow.h"

#include <QMessageBox>

addquestionwindow * questionwindow;

AddNewTestWindow::AddNewTestWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddNewTestWindow)
{
    questionwindow = new addquestionwindow();

    ui->setupUi(this);

    connect(this, SIGNAL(sendNumberOfQuestions(int)), questionwindow, SLOT(reciveNumberOfQuestions(int)));
}

AddNewTestWindow::~AddNewTestWindow()
{
    delete ui;
}

void AddNewTestWindow::on_addQuestions_pushButton_clicked()
{
    if(ui->questionsAmount_spinBox->value() == 0)
    {
        QMessageBox::information(0, "Ошибка", "Вы не задали количество вопросов!");
    }else
    {
        emit sendNumberOfQuestions(ui->questionsAmount_spinBox->value());
        questionwindow->show();
    }
}

void AddNewTestWindow::on_addTest_pushButton_clicked()
{
    if(ui->questionsAmount_spinBox->value() == 0)
    {
        QMessageBox::information(0, "Ошибка", "Вы не заполнили вопросы!");
    }
    else
    {
        QMessageBox::information(0, "Успех", "Тест успешно добавлен в систему!");
        this->close();
    }
}
