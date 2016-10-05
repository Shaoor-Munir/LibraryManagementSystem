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
    login.cpp \
    myDAL.cpp \
    lms_s.cpp \
    loginerror.cpp \
    adminmainwindow.cpp \
    adduser.cpp \
    additem.cpp

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
    login.h \
    myDAL.h \
    lms_s.h \
    loginerror.h \
    adminmainwindow.h \
    adduser.h \
    additem.h

FORMS    += \
    login.ui \
    loginerror.ui \
    adminmainwindow.ui \
    adduser.ui \
    additem.ui
