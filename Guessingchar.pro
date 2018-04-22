#-------------------------------------------------
#
# Project created by QtCreator 2018-04-21T22:00:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Guessingchar
TEMPLATE = app

INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lopencv_highgui -lopencv_videoio -ltesseract -llept

INCLUDEPATH += /usr/local/include/tesseract
INCLUDEPATH += /usr/local/include/leptonica

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
