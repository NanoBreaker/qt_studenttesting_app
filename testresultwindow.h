#ifndef TESTRESULTWINDOW_H
#define TESTRESULTWINDOW_H

#include <QWidget>

namespace Ui {
class TestResultWindow;
}

class TestResultWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TestResultWindow(QWidget *parent = 0);
    ~TestResultWindow();

private slots:
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::TestResultWindow *ui;
};

#endif // TESTRESULTWINDOW_H
