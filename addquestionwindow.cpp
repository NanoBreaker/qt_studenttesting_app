#include "addquestionwindow.h"
#include "ui_addquestionwindow.h"
#include "question.h"

#include <QVector>
#include <QMessageBox>

QVector<Question> queVector;

int numberOfQuestions;
int currentQuestionIndex;

addquestionwindow::addquestionwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addquestionwindow)
{
    ui->setupUi(this);

    currentQuestionIndex = 0;
    ui->questionNumber->setText(QString::number(currentQuestionIndex + 1));
}

addquestionwindow::~addquestionwindow()
{
    delete ui;
}

void addquestionwindow::reciveNumberOfQuestions(int _numberOfQuestions)
{
    numberOfQuestions = _numberOfQuestions;
    queVector.resize(_numberOfQuestions);
}

void addquestionwindow::saveQuestionList()
{
    queVector[currentQuestionIndex].questionString = ui->questionText->toPlainText();
    queVector[currentQuestionIndex].groups = ui->testAnswers->toPlainText();
}

void addquestionwindow::updateQuestionList()
{
    ui->questionNumber->setText(QString::number(currentQuestionIndex + 1));
    ui->questionText->setText(queVector[currentQuestionIndex].questionString);
    ui->testAnswers->setText(queVector[currentQuestionIndex].groups);
}

void addquestionwindow::on_prevQuestion_pushButton_clicked()
{
    if(currentQuestionIndex > 0)
    {
        saveQuestionList();
        currentQuestionIndex--;
        updateQuestionList();
    }
}

void addquestionwindow::on_finishAdding_pushButton_clicked()
{
    QMessageBox::information(0, "Успех", "Вопросы были успешно добавлены к данному тесту!");
    this->close();
}

void addquestionwindow::on_nextQuestion_pushButton_clicked()
{
    if(currentQuestionIndex < numberOfQuestions - 1)
    {
        saveQuestionList();
        currentQuestionIndex++;
        updateQuestionList();
    }
}
