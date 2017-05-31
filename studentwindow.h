#ifndef STUDENTWINDOW_H
#define STUDENTWINDOW_H

#include <QMainWindow>

namespace Ui {
class StudentWindow;
}

class StudentWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentWindow(QWidget *parent = 0);
    ~StudentWindow();

signals:
    void studentWindowIsClosedSend();

private slots:
    void on_checkBox_stateChanged(int arg1);

    void on_finishSession_pushButton_clicked();

    void on_treeWidget_doubleClicked(const QModelIndex &index);

    void on_pushButton_clicked();

private:
    Ui::StudentWindow *ui;
};

#endif // STUDENTWINDOW_H
