#ifndef VIDEOPLAYBACKWIN_H
#define VIDEOPLAYBACKWIN_H
#include <QPushButton>
#include <QAction>
#include <QString>
#include <QDebug>
#include <QGridLayout>
#include <QMessageBox>
#include <QWidget>
#include <QToolButton>
#include <QLabel>
#include <QComboBox>
#include<QSlider>
#include "videochoosewin.h"
#include "fdecode.h"
#include "fdecodeplay.h"
#include "fcodec_h264.h"
#include <QPaintEvent>
#include<QPainter>
#include <QImage>
#include "database.h"
class VideoPlaybackWin : public QWidget
{
    Q_OBJECT
public:
    explicit VideoPlaybackWin(QWidget *parent = 0);

    void paintEvent(QPaintEvent *);

     QGridLayout *glay;
     QLabel *LabTitle;//录像回放界面
     QLabel *LabVideo;//录像回放界面
     QPushButton *BtnVideo;
     QComboBox *CombSpeed;//下拉框：倍速
     QSlider *SliderPlayer;

     QToolButton *TlBtnReturn;
     QToolButton *TlBtnPlayOrStp;
     QToolButton *TlBtnLastVd;
     QToolButton *TlBtnNextVd;
     QToolButton *TlBtnPrintSc;

     QAction *ActReturn;
     QAction *ActPlayOrStp;
     QAction *ActLastVd;
     QAction *ActNextVd;
     QAction *ActPrintSc;

private:
//    fdecode *fdec;
    fdecodeplay *fdecp;
    QImage img;
    fcodec_h264 *fcodec;

signals:

public slots:
     void ReturnTlbtnSlot();//返回上个界面
     void PlayOrStpTlbtnSlot();
     void LastVdTlbtnSlot();
     void NextVdTlbtnSlot();
     void PrintScTlbtnSlot();//截图

     void recviceImage(QImage image);
     void recviceYUV(AVFrame *frame);
     void recviceEndFlag(int flag);//尾巴帧
};

#endif // VIDEOPLAYBACKWIN_H
