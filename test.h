#ifndef TEST_H
#define TEST_H

#include "question.h"

#include <QApplication>
#include <QVector>
#include <QTime>
#include <QDate>

class Test
{
public:
    Test();

    QString lecturerInformation;
    QString testInformation;
    QDate creationDate;
    QTime passingTime;

    int amountOfQuestions;

    QVector<Question> vectorOfQuestions;
};

#endif // TEST_H
