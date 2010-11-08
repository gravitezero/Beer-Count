#-------------------------------------------------
#
# Project created by QtCreator 2010-09-30T14:15:58
#
#-------------------------------------------------

QT       += core gui sql

TARGET = BeerCount
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    beer.cpp \
    facade.cpp \
    database.cpp

HEADERS  += mainwindow.h \
    beer.h \
    facade.h \
    database.h

FORMS    += mainwindow.ui
