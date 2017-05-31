#include "testpassing.h"
#include "ui_testpassing.h"
#include "question.h"
#include <QVector>
#include <QDebug>
#include <QtGlobal>
#include <QMessageBox>

QVector<Question> vectorOfQuestions;
int currentQuestion = 0;

TestPassing::TestPassing(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestPassing)
{
    ui->setupUi(this);

    Question question;
    question.questionString = "Кто придумал закон Ома?";
    question.vectorOfanswers.push_back("Ом, Георг Симон");
    question.vectorOfanswers.push_back("Владимир Владимиривич Путин");
    question.vectorOfanswers.push_back("Иосиф Сталин");
    question.vectorOfanswers.push_back("Будда");
    question.correctAnswer = 0;
    question.selectedAnswer = 0;
    vectorOfQuestions.push_back(question);

    Question question1;
    question1.questionString = "Что помогает от похмелья по утрам?";
    question1.vectorOfanswers.push_back("Доширак");
    question1.vectorOfanswers.push_back("Нахождение в отрезвители");
    question1.vectorOfanswers.push_back("Чтение квантовой физики");
    question1.vectorOfanswers.push_back("Биг-Бон");
    question1.correctAnswer = 3;
    question1.selectedAnswer = 0;
    vectorOfQuestions.push_back(question1);

    Question question2;
    question2.questionString = "Как долго будет править В.В. Путин?";
    question2.vectorOfanswers.push_back("Вечно");
    question2.vectorOfanswers.push_back("Не вечно");
    question2.vectorOfanswers.push_back("Почти вечно");
    question2.vectorOfanswers.push_back("Затрудняюсь ответить");
    question2.correctAnswer = 0;
    question2.selectedAnswer = 0;
    vectorOfQuestions.push_back(question2);

    Question question3;
    question3.questionString = "Где находиться ваше сознание?";
    question3.vectorOfanswers.push_back("В вашем сознание");
    question3.vectorOfanswers.push_back("Нигде");
    question3.vectorOfanswers.push_back("В сознание вашего кота - Барсика");
    question3.vectorOfanswers.push_back("Что есть сознание?");
    question3.correctAnswer = 2;
    question3.selectedAnswer = 0;
    vectorOfQuestions.push_back(question3);

    Question question4;
    question4.questionString = "От чего зависит цена хлеба?";
    question4.vectorOfanswers.push_back("От успеха тура Иосифа Кобзона на Марсе");
    question4.vectorOfanswers.push_back("От восприятия цены");
    question4.vectorOfanswers.push_back("От цены нефти");
    question4.vectorOfanswers.push_back("От положения Альфа-Центавры относительно галактики Андромеда");
    question4.correctAnswer = 3;
    question4.selectedAnswer = 0;
    vectorOfQuestions.push_back(question4);

    ui->questionSelect_comboBox->addItems(vectorOfQuestions[currentQuestion].vectorOfanswers.toList());
    updateInfo();
}

TestPassing::~TestPassing()
{
    delete ui;
}

void TestPassing::updateInfo()
{
    ui->lineEdit->setText(QString::number(currentQuestion + 1));
    ui->textEdit->setText(vectorOfQuestions[currentQuestion].questionString);
    for(int i = 0; i < 4; i++)
    {
        ui->questionSelect_comboBox->setItemText(i, vectorOfQuestions[currentQuestion].vectorOfanswers[i]);
    }
    ui->questionSelect_comboBox->update();
    ui->questionSelect_comboBox->setCurrentIndex( vectorOfQuestions[currentQuestion].selectedAnswer);
}

void TestPassing::on_questionSelect_comboBox_currentIndexChanged(int index)
{
    vectorOfQuestions[currentQuestion].selectedAnswer = index;
}

void TestPassing::on_previousQuestion_pushButton_clicked()
{
    if(currentQuestion > 0)
    {
        currentQuestion--;
        updateInfo();
    }
}

void TestPassing::on_nextQuestion_pushButton_clicked()
{
    if(currentQuestion < 4)
    {
        currentQuestion++;
        updateInfo();
    }
}

void TestPassing::on_finishTest_pushButton_clicked()
{
    int random = qrand() % 5;
    QString str = QString::number(random);
    str = "Количетсво правильных ответов " + str + "/5";

    QMessageBox::information(0, "Тест завершен", str);
    this->close();
}
