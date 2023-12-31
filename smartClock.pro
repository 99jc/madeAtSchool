######################################################################
# Automatically generated by qmake (3.1) Sun Nov 27 10:58:51 2022
######################################################################

TEMPLATE = app
TARGET = smartClock
INCLUDEPATH += .

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
CONFIG += no_keywords
QT += widgets multimediawidgets
LIBS += -lwiringPi -L /usr/local/lib/python3.9 -lpython3.9
INCLUDEPATH += /usr/include/python3.9
DEPENDPATH += /usr/include/python3.9
HEADERS += ClockWindow.h THThread.h PyThread.h
SOURCES += ClockWindow.cpp smartClock.cpp THThread.cpp PyThread.cpp TH.c
