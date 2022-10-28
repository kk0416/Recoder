#-------------------------------------------------
#
# Project created by QtCreator 2022-02-12T09:47:10
#
#-------------------------------------------------

QT       += core gui\
            multimedia\
            widgets# 日历

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = recoder
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
LIBS += $$PWD/lib/sqlite3.lib

SOURCES += main.cpp\
    settingswin.cpp \
    registerwin.cpp \
    animationwin.cpp \
    mainwin.cpp \
    myview.cpp \
    myitem.cpp \
    loginwin.cpp \
    verificationcodelabel.cpp \
    database.cpp \
    videoplaybackwin.cpp \
    videochoosewin.cpp \
    fcodec_h264.cpp \
    fdecode.cpp \
    pictoviewwin.cpp \
    calendarkj.cpp \
    fdecodeplay.cpp

HEADERS  += \
    settingswin.h \
    registerwin.h \
    animationwin.h \
    mainwin.h \
    myview.h \
    myitem.h \
    loginwin.h \
    verificationcodelabel.h \
    database.h \
    videoplaybackwin.h \
    videochoosewin.h \
    fcodec_h264.h \
    fdecode.h \
    pictoviewwin.h \
    calendarkj.h \
    fdecodeplay.h

RESOURCES += \
    image.qrc

INCLUDEPATH +=$$PWD/ffmpeglib/include
LIBS += $$PWD/ffmpeglib/lib/avcodec.lib \
        $$PWD/ffmpeglib/lib/avdevice.lib \
        $$PWD/ffmpeglib/lib/avfilter.lib \
        $$PWD/ffmpeglib/lib/avformat.lib \
        $$PWD/ffmpeglib/lib/avutil.lib \
        $$PWD/ffmpeglib/lib/postproc.lib \
        $$PWD/ffmpeglib/lib/swresample.lib \
        $$PWD/ffmpeglib/lib/swscale.lib
