#ifndef FDECODEPLAY_H
#define FDECODEPLAY_H
#include <QString>
#include <QThread>
#include <QImage>
#include <QDebug>
#include "database.h"
#include <QDateTime>
#include <QMessageBox>
//#include "fcodec_h264.h"
extern "C"
{
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libavutil/avutil.h>
    #include <libswresample/swresample.h>
    #include <libswscale/swscale.h>
    #include <libavdevice/avdevice.h>
}
//播放视频
class fdecodeplay : public QThread
{
    Q_OBJECT
public:
    fdecodeplay();
    virtual ~fdecodeplay() {}

    void registerFFmpeg();//注册组件
    void openViedoStream_play(QString filename);//
    void run();//重写线程中的run 执行线程要执行的任务

    Cdatabase *mydb;
    static int playflag;//视频播放标志位
    static int scrflag;//视频截图标志位
    static int posflag;
    static QString picname;//从录像选择界面返回run



    static void setPicname(const QString &value);

signals://信号：
    void sendImage(QImage img);//将解码得到的一张图片信息发送给槽
    void sendYUV(AVFrame *frame);
    void sendEndFlag(int flag);//结束判断
private:
    //编码对象
//    fcodec_h264 *fcodec;

};

#endif // FDECODEPLAY_H
