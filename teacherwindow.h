#ifndef TEACHERWINDOW_H
#define TEACHERWINDOW_H

#include <QMainWindow>

namespace Ui {
class TeacherWindow;
}

class TeacherWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TeacherWindow(QWidget *parent = 0);
    ~TeacherWindow();

private slots:
    void on_checkBox_stateChanged(int arg1);

    void on_finishSession_pushButton_clicked();

    void on_addNewTest_pushButton_clicked();

    void on_treeWidget_doubleClicked(const QModelIndex &index);

    void on_startTest_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

signals:
    void teacherWindowIsClosedSend();

private:
    Ui::TeacherWindow *ui;
};

#endif // TEACHERWINDOW_H
