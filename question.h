#ifndef QUESTION_H
#define QUESTION_H

#include <QApplication>
#include <QVector>

class Question
{
public:
    Question();

    QString questionString;
    QString groups;

    QVector<QString> vectorOfanswers;

    int correctAnswer;
    int selectedAnswer;
};

#endif // QUESTION_H
