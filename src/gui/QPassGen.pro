QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QPassGen
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    consoleworker.cpp

HEADERS  += mainwindow.h \
    consoleworker.h

FORMS    += mainwindow.ui
