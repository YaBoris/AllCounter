#-------------------------------------------------
#
# Project created by QtCreator 2017-03-09T15:19:42
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AllCounter
TEMPLATE = app

SOURCES += main.cpp\
	mainwindow.cpp \
	windowaddnewposition.cpp \
	windowsetfeaturesfornewtypedevice.cpp \
	windowaddnewfeaturetofeaturelist.cpp \
	windowselectfeaturevalues.cpp \
	brokerdb.cpp \
    control.cpp
#	control_rec.cpp \
#	workwithdevice.cpp

HEADERS  += mainwindow.h \
	windowaddnewposition.h \
	windowsetfeaturesfornewtypedevice.h \
	windowaddnewfeaturetofeaturelist.h \
	windowselectfeaturevalues.h \
	brokerdb.h \
    control.h
#	control_rec.h \
#	workwithdevice.h

FORMS    += mainwindow.ui \
	windowaddnewposition.ui \
	windowsetfeaturesfornewtypedevice.ui \
	windowaddnewfeaturetofeaturelist.ui \
	windowselectfeaturevalues.ui
#	workwithdevice.ui

RESOURCES += \
	icons.qrc

