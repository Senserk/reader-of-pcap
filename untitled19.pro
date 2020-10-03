TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

INCLUDEPATH += C:\Users\pc\Desktop\WpdPack\Include
LIBS += "-LC:\Users\pc\Desktop\WpdPack\Lib" -lwpcap -lpacket


DEFINES += WPCAP
DEFINES += HAVE_REMOTE
