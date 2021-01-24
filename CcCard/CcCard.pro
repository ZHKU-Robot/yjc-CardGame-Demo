#-------------------------------------------------
#
# Project created by QtCreator 2021-01-11T12:03:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CcCard
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
OBJECTS_DIR  = .

MOC_DIR      = .

SOURCES += \
        main.cpp \
        cccardgame.cpp \
    fightinterface.cpp \
    cardgroupframe.cpp \
    cardwidget.cpp \
    cardgraphicsproxywidget.cpp \
    fightgraphicsview.cpp \
    aewidget.cpp \
    character.cpp\
qtjsonop.cpp \
    characterstatusbar.cpp \
    finishedturnbtn.cpp \
    mpbar.cpp


HEADERS += \
        cccardgame.h \
    fightinterface.h \
    cardgroupframe.h \
    cardwidget.h \
    cardgraphicsproxywidget.h \
    global.h \
    fightgraphicsview.h \
    aewidget.h \
    character.h\
qtjsonop.h \
    characterstatusbar.h \
    finishedturnbtn.h \
    mpbar.h


FORMS += \
        cccardgame.ui \
    fightinterface.ui \
    cardwidget.ui \
    characterstatusbar.ui \
    finishedturnbtn.ui \
    mpbar.ui


RESOURCES += \
    gameimg.qrc
