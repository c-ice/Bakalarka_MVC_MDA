#-------------------------------------------------
#
# Project created by QtCreator 2012-04-06T12:18:37
#
#-------------------------------------------------

QT       += core gui

TARGET = Bakalarka_MVC_MDA
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Base/datatype.cpp \
    Widgets/projectfileswidget.cpp \
    Base/projectfilemodel.cpp

HEADERS  += mainwindow.h \
    Base/datatype.h \
    Widgets/projectfileswidget.h \
    Base/projectfilemodel.h

FORMS    += mainwindow.ui \
    Widgets/projectfileswidget.ui

RESOURCES += \
    images.qrc

OTHER_FILES += \
    images/undo.png \
    images/save.png \
    images/print.png \
    images/new.png

