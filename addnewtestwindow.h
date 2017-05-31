#ifndef ADDNEWTESTWINDOW_H
#define ADDNEWTESTWINDOW_H

#include <QWidget>

namespace Ui {
class AddNewTestWindow;
}

class AddNewTestWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AddNewTestWindow(QWidget *parent = 0);
    ~AddNewTestWindow();

private slots:
    void on_addQuestions_pushButton_clicked();

    void on_addTest_pushButton_clicked();

signals:
    void sendNumberOfQuestions(int numberOfQuestions);

private:
    Ui::AddNewTestWindow *ui;
};

#endif // ADDNEWTESTWINDOW_H
