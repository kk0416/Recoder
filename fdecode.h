#ifndef FDECODE_H
#define FDECODE_H
#include <QString>
#include <QThread>
#include <QImage>
#include "fcodec_h264.h"
#include <QDebug>
#include <QDateTime>
#include <QByteArray>
#include "database.h"
#include <QCameraInfo>
#include <QMessageBox>
class fdecode : public QThread
{
    Q_OBJECT
public:
    fdecode();
    Cdatabase *mydb;

    static qint16 ptidcount;//计数

    QString camera;



    virtual ~fdecode() {}
    void registerFFmpeg();//注册组件
    void openViedoStream_jiema(QString filename);//

    void run();//重写线程中的run 执行线程要执行的任务

    static int pixflag;//拍照标志位
    static int posflag;//暂停
    static int playflag;//视频播放标志位
    static QString picname;//从录像选择界面返回run

    void setCamera(const QString &value);



   static void setPicname(const QString &value);//set函数

//静态的函数：获取对象指针访问接口
//   static fdecode *getfdec();

signals://信号：
    void sendImage(QImage img);//将解码得到的一张图片信息发送给槽
    void sendYUV(AVFrame *frame);
    void sendEndFlag(int flag);//结束判断
private:
    //编码对象
    fcodec_h264 *fcodec;

//构造私有化

//私有静态对象指针
//    static fdecode *pfdec;

};
#endif // FDECODE_H
