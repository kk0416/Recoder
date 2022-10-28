#include <QDebug>
#include <QApplication>
#include "myview.h"//开机动画
#include "mainwin.h"
#include "loginwin.h"
#include "verificationcodelabel.h"//验证码
#include "settingswin.h"//设置
#include "database.h"
#include "videochoosewin.h"
#include "videoplaybackwin.h"//录像回放
//#include "playerwidget.h"
#include "fcodec_h264.h"
#include "fdecode.h"
#include "pictoviewwin.h"
#include "calendarkj.h"
extern "C"
{
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libavutil/avutil.h>
    #include <libswresample/swresample.h>
    #include <libavdevice/avdevice.h>
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    mainWin *w=mainWin::getpmainwin();
    MyView w;//开机动画
//    LoginWin w;
//    VerificationCodeLabel w;//单独验证码

//    mainWin w;
//    VideoChooseWin w;
//    settingsWin w;
//    Cdatabase *w=Cdatabase::getSignal();
//    VideoPlaybackWin w;
//    PicToViewWin w;
    w.show();
//
//     qDebug()<<avcodec_version()<<endl;//测试ffmpeg

//     PlayerWidget *play=new PlayerWidget;//摄像头
//     play->show();
    return a.exec();
}
