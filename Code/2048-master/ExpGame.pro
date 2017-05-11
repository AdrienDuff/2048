QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ExpGame
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        gui/mainwindow.cpp \
    core/board.cpp \
    core/game.cpp \
    gui/qgameboard.cpp \
    gui/qresetbutton.cpp \
    core/observer.cpp \
    core/subject.cpp \
    gui/qgameoverwindow.cpp \
    core/tile.cpp \
    gui/qtile.cpp

HEADERS  += gui/mainwindow.h \
    core/board.h \
    core/game.h \
    gui/qgameboard.h \
    gui/qtile.h \
    gui/qresetbutton.h \
    core/observer.h \
    core/subject.h \
    gui/qgameoverwindow.h \
    gui/qwinwindow.h \
    menu.h \
    core/tile.h

