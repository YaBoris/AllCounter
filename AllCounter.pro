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
#	addcompcase.cpp \
#	addmonitor.cpp \
#	addkeyboard.cpp \
#	addmouse.cpp \
#	addswitch.cpp \
#	addprintera4.cpp \
#	addprinterzebra.cpp \
#	addtsd.cpp \
#	addnotebook.cpp \
#	addphone.cpp \
#	addwifi.cpp \
#	addphoto.cpp \
#	addcharger.cpp \
#	addhoover.cpp \
	brokerdb.cpp \
	addwiredscanner.cpp \
	control_rec.cpp \
	addwirelescan.cpp

HEADERS  += mainwindow.h \
#	addcompcase.h \
#	addmonitor.h \
#	addkeyboard.h \
#	addmouse.h \
#	addswitch.h \
#	addprintera4.h \
#	addprinterzebra.h \
#	addtsd.h \
#	addnotebook.h \
#	addphone.h \
#	addwifi.h \
#	addphoto.h \
#	addcharger.h \
#	addhoover.h \
	brokerdb.h \
	addwiredscanner.h \
	control_rec.h \
	addwirelescan.h

FORMS    += mainwindow.ui \
#	addcompcase.ui \
#	addmonitor.ui \
#	addkeyboard.ui \
#	addmouse.ui \
#	addswitch.ui \
#	addprintera4.ui \
#	addprinterzebra.ui \
#	addtsd.ui \
#	addnotebook.ui \
#	addphone.ui \
#	addwifi.ui \
#	addphoto.ui \
#	addcharger.ui \
#	addhoover.ui \
	addwiredscanner.ui \
	addwirelescan.ui

RESOURCES += \
	icons.qrc

