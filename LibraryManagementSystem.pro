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
    lms.cpp \
    libitem.cpp \
    user.cpp \
    loanitem.cpp \
    book.cpp \
    dvd.cpp \
    student.cpp \
    admin.cpp \
    clerk.cpp \
    lms_s.cpp \
    adduser.cpp \
    additem.cpp \
    loginwindow.cpp \
    mainwindow.cpp \
    userdetails.cpp \
    userloans.cpp \
    issueitem.cpp \
    itemsearch.cpp \
    edituser.cpp \
    edititem.cpp \
    removeloan.cpp

HEADERS  += \
    lms.h \
    libitem.h \
    user.h \
    loanitem.h \
    book.h \
    dvd.h \
    student.h \
    admin.h \
    clerk.h \
    lms_s.h \
    adduser.h \
    additem.h \
    loginwindow.h \
    mainwindow.h \
    userdetails.h \
    userloans.h \
    issueitem.h \
    itemsearch.h \
    edituser.h \
    edititem.h \
    removeloan.h

FORMS    += \
    adduser.ui \
    additem.ui \
    loginwindow.ui \
    mainwindow.ui \
    userdetails.ui \
    userloans.ui \
    issueitem.ui \
    itemsearch.ui \
    edituser.ui \
    edititem.ui \
    removeloan.ui
