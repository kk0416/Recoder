#ifndef MAINWIN_H
#define MAINWIN_H
#include <QPushButton>
#include <QHBoxLayout>//水平布局
#include <QVBoxLayout>//垂直布局
#include <QGridLayout>
#include <QWidget>
#include <QLabel>
#include <QString>
#include <QDebug>
//#include "loginwin.h"
#include "registerwin.h"
#include "settingswin.h"
#include "videoplaybackwin.h"
#include "videochoosewin.h"
#include "fdecode.h"
#include "fcodec_h264.h"
#include <QPaintEvent>
#include<QPainter>
#include <QImage>
#include "pictoviewwin.h"


class LoginWin;//防止两个类头文件互相包含

class mainWin : public QWidget
{
    Q_OBJECT
public:


    void paintEvent(QPaintEvent *);


    LoginWin *log1;

    QGridLayout *glay;
    QPushButton *BtnVideo;
    QPushButton *BtnTakPic;//现场拍照
    QPushButton *BtnSeePic;//现场图片
    QPushButton *BtnBakVid;//录像回放
    QPushButton *BtnSeeLog;//查看日志
    QPushButton *BtnTrsVid;//录像转码
    QPushButton *BtnLogin;//登录
    QPushButton *BtnReturn;//退出
    QPushButton *BtnRgs;//注册
    QPushButton *BtnSettings;//系统设置

    QLabel *LabTitle;//执法记录仪主界面


    //静态的函数：获取对象指针访问接口
    static mainWin *getpmainwin();

private:
    fdecode *fdec;
    QImage img;
    fcodec_h264 *fcodec;

    explicit mainWin(QWidget *parent = 0);
    static mainWin *pmainwin;

signals:

public slots:
    void recviceImage(QImage image);
    void recviceYUV(AVFrame *frame);
    void recviceEndFlag(int flag);//尾巴帧
    void BtnSlot();
};

#endif // MAINWIN_H
