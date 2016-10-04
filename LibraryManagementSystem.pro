#-------------------------------------------------
#
# Project created by QtCreator 2016-10-04T23:25:40
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LibraryManagementSystem
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    lms.cpp \
    libitem.cpp \
    user.cpp \
    loanitem.cpp \
    book.cpp \
    dvd.cpp \
    student.cpp \
    admin.cpp \
    clerk.cpp \
    login.cpp \
    myDAL.cpp

HEADERS  += mainwindow.h \
    lms.h \
    libitem.h \
    user.h \
    loanitem.h \
    book.h \
    dvd.h \
    student.h \
    admin.h \
    clerk.h \
    login.h \
    myDAL.h

FORMS    += mainwindow.ui \
    login.ui
