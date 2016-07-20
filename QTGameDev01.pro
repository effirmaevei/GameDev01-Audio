#-------------------------------------------------
#
# Project created by QtCreator 2016-07-17T16:45:31
#
#-------------------------------------------------

QT       += core gui \
        multimedia          #Added Multimedia line to handle sounds/video

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTGameDev01
TEMPLATE = app


SOURCES += main.cpp \
    Bullet.cpp \
    Enemy.cpp \
    Constants.cpp \
    Game.cpp \
    Score.cpp \
    Player.cpp \
    Health.cpp

HEADERS  += \
    Bullet.h \
    Enemy.h \
    Constants.h \
    Game.h \
    Score.h \
    Player.h \
    Health.h

RESOURCES += \
    res.qrc
