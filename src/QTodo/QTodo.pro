#-------------------------------------------------
#
# Project created by QtCreator 2015-01-06T12:16:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTodo
TEMPLATE = app

include(./lib/jsoncpp/jsoncpp.pri)

SOURCES += main.cpp\
        QTodoMainWin.cpp \
    Widgets/QTodoItemWidget.cpp \
    Data/Serialize.cpp \
    Data/TodoItem.cpp \
    Data/TodoData.cpp \
    Widgets/QTodoItemDetailWidget.cpp

HEADERS  += QTodoMainWin.h \
    Widgets/QTodoItemWidget.h \
    includes.h \
    types.h \
    Data/Serialize.h \
    Data/TodoItem.h \
    Data/TodoData.h \
    Widgets/QTodoItemDetailWidget.h

FORMS    += QTodoMainWin.ui \
    Widgets/QTodoItemWidget.ui \
    Widgets/QTodoItemDetailWidget.ui

RESOURCES += \
    Resources/resources.qrc
