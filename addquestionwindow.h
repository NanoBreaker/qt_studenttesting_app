#ifndef ADDQUESTIONWINDOW_H
#define ADDQUESTIONWINDOW_H

#include <QWidget>

namespace Ui {
class addquestionwindow;
}

class addquestionwindow : public QWidget
{
    Q_OBJECT

public:
    explicit addquestionwindow(QWidget *parent = 0);
    ~addquestionwindow();

private slots:
    void reciveNumberOfQuestions(int numberOfQuestions);

    void on_prevQuestion_pushButton_clicked();

    void on_finishAdding_pushButton_clicked();

    void on_nextQuestion_pushButton_clicked();

private:
    Ui::addquestionwindow *ui;

    void updateQuestionList();
    void saveQuestionList();
};

#endif // ADDQUESTIONWINDOW_H
