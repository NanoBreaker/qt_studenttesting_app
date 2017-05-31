#ifndef TESTPASSING_H
#define TESTPASSING_H

#include <QWidget>

namespace Ui {
class TestPassing;
}

class TestPassing : public QWidget
{
    Q_OBJECT

public:
    explicit TestPassing(QWidget *parent = 0);
    ~TestPassing();

private slots:
    void on_pushButton_clicked();

    void on_questionSelect_comboBox_currentIndexChanged(int index);

    void on_previousQuestion_pushButton_clicked();

    void on_nextQuestion_pushButton_clicked();

    void on_finishTest_pushButton_clicked();

private:
    Ui::TestPassing *ui;

    void updateInfo(void);
};

#endif // TESTPASSING_H
