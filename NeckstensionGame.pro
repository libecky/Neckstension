#-------------------------------------------------
#
# Project created by QtCreator 2016-01-31T14:34:08
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NeckstensionGame
TEMPLATE = app


SOURCES += main.cpp \
    food.cpp \
    game.cpp \
    score.cpp \
    giraffe.cpp \
    lives.cpp \
    mainwindow.cpp \
    instructionwindow.cpp \
    gameoverwindow.cpp \
    neck.cpp

HEADERS  += \
    food.h \
    game.h \
    score.h \
    giraffe.h \
    lives.h \
    mainwindow.h \
    instructionwindow.h \
    gameoverwindow.h \
    neck.h

FORMS    += \
    gameboard.ui \
    mainwindow.ui \
    instructionwindow.ui \
    gameoverwindow.ui

RESOURCES += \
    resources.qrc

DISTFILES +=
