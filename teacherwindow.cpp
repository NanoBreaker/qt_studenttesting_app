#include "teacherwindow.h"
#include "ui_teacherwindow.h"
#include "addnewtestwindow.h"
#include "testpassing.h"
#include "testresultwindow.h"

#include "test.h"
#include "question.h"

#include <QVector>
#include <QTime>
#include <QDate>
#include <QMessageBox>

AddNewTestWindow * addNewTestWindow;
TestPassing * testPassing;
TestResultWindow * testResultWindow;

QVector<Test> vectorOfTests;

int selectedTestIndex;

TeacherWindow::TeacherWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TeacherWindow)
{
    ui->setupUi(this);

    addNewTestWindow = new AddNewTestWindow();
    testPassing = new TestPassing();
    testResultWindow = new TestResultWindow();

    QPalette p = ui->userFIO_lineEdit->palette();
    p.setColor(QPalette::Base, Qt::green);
    ui->userFIO_lineEdit->setPalette(p);
    ui->userFIO_lineEdit->setText("Поламарчук Лариса Николаевна");

    Test first_test;
    first_test.lecturerInformation = "Поламарчук Лариса Николаевна";
    first_test.testInformation = "Тест на тему множества\nИнформация о тесте . . .";
    first_test.amountOfQuestions = 5;
    first_test.creationDate = QDate(2017,01,10);
    first_test.passingTime = QTime(0, 10, 0, 0);
    vectorOfTests.push_back(first_test);

    first_test.lecturerInformation = "Поламарчук Лариса Николаевна";
    first_test.testInformation = "Тест на тему уравнений\nПлатформер является продолжением Sonic Rush. Игровой процесс сиквела не подвергся кардинальным изменениям: от игрока всё так же требуется пройти несколько уровней, по пути уничтожая врагов и собирая золотые кольца. Исследуют игровые зоны два персонажа — ёж Соник и кошка Блейз. Сюжетная линия строится вокруг приключений команды Соника на Южном Острове и их борьбы против союза врагов — доктора Эггмана и Эггмана Неги.";
    first_test.amountOfQuestions = 10;
    first_test.creationDate = QDate(2017,12,15);
    first_test.passingTime = QTime(0, 15, 0, 0);
    vectorOfTests.push_back(first_test);

    first_test.lecturerInformation = "Поламарчук Лариса Николаевна";
    first_test.testInformation = "Разработка Sonic Rush Adventure началась в 2006 году. Благодаря высоким продажам Sonic Rush, команда решила создать на её основе продолжение. В ходе разработки проекта студии внесли некоторые изменения и улучшения в игровой процесс и визуальный стиль. После выхода платформер получил от прессы положительные отзывы. К достоинствам игры были отнесены геймплей и графика, но критике подверглись уровни и сюжет.";
    first_test.amountOfQuestions = 15;
    first_test.creationDate = QDate(2017,05,05);
    first_test.passingTime = QTime(0, 15, 0, 0);
    vectorOfTests.push_back(first_test);

    first_test.lecturerInformation = "Поламарчук Лариса Николаевна";
    first_test.testInformation = "30 июня 1960 года в Бельгийском Конго была провозглашена независимость, после чего в стране началась гражданская война. 14 сентября 1960 года Мобуту, уже имевший звание полковника и должность начальника генерального штаба, при поддержке США совершил военный переворот. В 1961 году Мобуту передал власть гражданским, а в 1965 году вновь осуществил путч, в результате которого он окончательно пришёл к власти в стране. После этого Мобуту установил однопартийный авторитарный режим и провозгласил курс на «аутентичность», выражавшуюся в отказе от европейских имён, топонимов, обращений и костюмов. В 1971 году страна была переименована в Заир. Мобуту был свергнут повстанцами в 1997 году. После этого бежал сначала в Того, затем в Марокко, где и умер 7 сентября 1997 года.";
    first_test.amountOfQuestions = 5;
    first_test.creationDate = QDate(2017,11,25);
    first_test.passingTime = QTime(0, 5, 0, 0);
    vectorOfTests.push_back(first_test);

}

TeacherWindow::~TeacherWindow()
{
    delete ui;
}

void TeacherWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1) ui->groupBox_2->setEnabled(1);
    else ui->groupBox_2->setEnabled(0);
}

void TeacherWindow::on_finishSession_pushButton_clicked()
{
    this->setVisible(false);
    emit teacherWindowIsClosedSend();
}

void TeacherWindow::on_addNewTest_pushButton_clicked()
{
    addNewTestWindow->show();
}

void TeacherWindow::on_treeWidget_doubleClicked(const QModelIndex &index)
{
    if(index.row() <= vectorOfTests.size())
    {
        ui->testInformation_textEdit->setText(vectorOfTests[index.row()].testInformation);
        ui->numberOfQuestions_lineEdit->setText(QString::number(vectorOfTests[index.row()].amountOfQuestions));
        ui->testDate_lineEdit->setText(vectorOfTests[index.row()].creationDate.toString());
        ui->testTime_lineEdit->setText(vectorOfTests[index.row()].passingTime.toString());
        selectedTestIndex = index.row();
    }
}

void TeacherWindow::on_startTest_pushButton_clicked()
{
    testPassing->show();
}

void TeacherWindow::on_pushButton_2_clicked()
{
    testResultWindow->show();
}

void TeacherWindow::on_pushButton_4_clicked()
{
    QMessageBox::information(0, "Успех", "Данный тест был успешно удалён из системы!");
}
