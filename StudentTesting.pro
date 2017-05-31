#-------------------------------------------------
#
# Project created by QtCreator 2016-12-30T07:21:23
#
#-------------------------------------------------

QT       += core gui
QT       += core sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StudentTesting
TEMPLATE = app


SOURCES += main.cpp\
        authorizationwindow.cpp \
    teacherwindow.cpp \
    addnewtestwindow.cpp \
    studentwindow.cpp \
    test.cpp \
    question.cpp \
    addquestionwindow.cpp \
    testpassing.cpp \
    testresultwindow.cpp \
    testpassingclass.cpp \
    superuser.cpp \
    mysqlcontroller.cpp \
    userfacade.cpp

HEADERS  += authorizationwindow.h \
    teacherwindow.h \
    addnewtestwindow.h \
    studentwindow.h \
    test.h \
    question.h \
    addquestionwindow.h \
    testpassing.h \
    testresultwindow.h \
    testpassingclass.h \
    superuser.h \
    mysqlcontroller.h \
    userfacade.h

FORMS    += authorizationwindow.ui \
    teacherwindow.ui \
    addnewtestwindow.ui \
    studentwindow.ui \
    addquestionwindow.ui \
    testpassing.ui \
    testresultwindow.ui
