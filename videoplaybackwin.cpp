#include "videoplaybackwin.h"

VideoPlaybackWin::VideoPlaybackWin(QWidget *parent) : QWidget(parent)
{


    this->setMaximumSize(400,600);//固定尺寸
    this->setMinimumSize(400,600);
    this->setWindowTitle("录像回放界面");

//播放录像按钮
    BtnVideo=new QPushButton;
    BtnVideo->setIconSize(QSize(340,500));
    BtnVideo->setFixedHeight(300);
    BtnVideo->setFixedWidth(360);


//播放进度条
    SliderPlayer = new QSlider(Qt::Horizontal);	//Qt::Horizontal设置为水平的滑动条
    SliderPlayer->setMinimum(0);      // 设置滑动条的最小值
    SliderPlayer->setMaximum(100);
    SliderPlayer->setValue(0);
//    SliderPlayer->resize(500,50);
    SliderPlayer->setFixedSize(550,30);
//初始化
    glay=new QGridLayout(this);
    LabTitle=new QLabel("回放");
    LabTitle->setStyleSheet("QLabel{font:20px;color:99ff99;background-color:rgb(99,f9,f9);}");
    LabVideo=new QLabel("录像");
    TlBtnReturn = new QToolButton(this);
    TlBtnPlayOrStp = new QToolButton(this);
    TlBtnLastVd = new QToolButton(this);
    TlBtnNextVd = new QToolButton(this);
    TlBtnPrintSc = new QToolButton(this);

    ActReturn = new QAction(this);
    ActPlayOrStp = new QAction(this);
    ActLastVd = new QAction(this);
    ActNextVd = new QAction(this);
    ActPrintSc = new QAction(this);

    ActReturn->setIcon(QIcon(":/image/player/return.png"));
    TlBtnReturn->setIconSize(QSize(48, 48));
    TlBtnReturn->setDefaultAction(ActReturn);
    ActPlayOrStp->setIcon(QIcon(":/image/player/play.png"));
    TlBtnPlayOrStp->setIconSize(QSize(48, 48));
    TlBtnPlayOrStp->setDefaultAction(ActPlayOrStp);
    ActLastVd->setIcon(QIcon(":/image/player/next.png"));
    TlBtnLastVd->setIconSize(QSize(48, 48));
    TlBtnLastVd->setDefaultAction(ActLastVd);
    ActNextVd->setIcon(QIcon(":/image/player/next.png"));
    TlBtnNextVd->setIconSize(QSize(48, 48));
    TlBtnNextVd->setDefaultAction(ActNextVd);
    ActPrintSc->setIcon(QIcon(":/image/player/jt.png"));
    TlBtnPrintSc->setIconSize(QSize(48, 48));
    TlBtnPrintSc->setDefaultAction(ActPrintSc);
//下拉框
    CombSpeed=new QComboBox;
    CombSpeed->setEditable(true);
    CombSpeed->addItem("1倍速");
    CombSpeed->addItem("1.25");
    CombSpeed->addItem("1.5");
    CombSpeed->addItem("2");
//布局位置
    glay->addWidget(LabTitle,0,3,1,1);
    glay->addWidget(TlBtnReturn,1,0,1,1);//水平居右，垂直居中
    glay->addWidget(BtnVideo,2,0,6,6);
    glay->addWidget(SliderPlayer,8,0,1,6,Qt::AlignLeft | Qt::AlignVCenter);
    glay->addWidget(TlBtnPlayOrStp,9,1,1,1,Qt::AlignRight | Qt::AlignVCenter);
    glay->addWidget(TlBtnLastVd,9,0,1,1,Qt::AlignRight | Qt::AlignVCenter);
    glay->addWidget(TlBtnNextVd,9,2,1,1,Qt::AlignRight | Qt::AlignVCenter);
    glay->addWidget(CombSpeed,9,4,1,1,Qt::AlignRight | Qt::AlignVCenter);
    glay->addWidget(TlBtnPrintSc,9,5,1,1,Qt::AlignRight | Qt::AlignVCenter);


//    //创建解码线程对象
//    fdec =new fdecode;
//    fdec->start();
    //创建解码线程对象
    fdecp =new fdecodeplay;
    fdecp->start();
    //创建编码对象 写线程
    fcodec=new fcodec_h264;
    fcodec->codeInit();//初始化

    connect(fdecp,SIGNAL(sendYUV(AVFrame*)),this,SLOT(recviceYUV(AVFrame*)));//编码
    connect(fdecp,SIGNAL(sendEndFlag(int)),this,SLOT(recviceEndFlag(int)));//结束帧
    connect(fdecp,SIGNAL(sendImage(QImage)),this,SLOT(recviceImage(QImage)));

//信号与槽连接
    connect(TlBtnReturn,SIGNAL(clicked(bool)),this,SLOT(ReturnTlbtnSlot()));//返回录像选择界面
    connect(TlBtnPrintSc,SIGNAL(clicked(bool)),this,SLOT(PrintScTlbtnSlot()));//截屏
    connect(TlBtnPlayOrStp,SIGNAL(clicked(bool)),this,SLOT(PlayOrStpTlbtnSlot()));//暂停

}

void VideoPlaybackWin::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/bg/11.jpg");
    painter.drawPixmap(0,0,400,600,pix);
    if(!this->img.isNull())
    {

       this->img.scaled(this->BtnVideo->size());
        QPixmap Apixmap=QPixmap::fromImage(img);
        BtnVideo->setIcon(QIcon(Apixmap));
    }
}


//返回录像选择界面
void VideoPlaybackWin::ReturnTlbtnSlot()
{
    VideoChooseWin *VdChos=new VideoChooseWin;
    VdChos->show();
    this->hide();

}

void VideoPlaybackWin::PlayOrStpTlbtnSlot()
{
    if(fdecodeplay::posflag==0)
    {
        fdecodeplay::posflag=1;
        QMessageBox::information(this,"视频暂停","视频暂停成功");
    }
    else
    {
       fdecodeplay::posflag=0;
       QMessageBox::information(this,"继续播放","继续播放视频");
    }

}

void VideoPlaybackWin::LastVdTlbtnSlot()
{

}

void VideoPlaybackWin::NextVdTlbtnSlot()
{

}

void VideoPlaybackWin::PrintScTlbtnSlot()
{
    fdecodeplay::scrflag=1;
    QMessageBox::information(this,"视频截图","截图成功");


}



void VideoPlaybackWin::recviceImage(QImage image)
{
    this->img=image;
    this->update();//接收一张图片，更新一下，重绘界面
}

void VideoPlaybackWin::recviceYUV(AVFrame *frame)
{
//    qDebug()<<"/接收到一帧 就编码：需要一个编码对象->调用编码函数";
    //接收到一帧 就编码：需要一个编码对象->调用编码函数
    fcodec->codecFrame(frame);
}

void VideoPlaybackWin::recviceEndFlag(int flag)
{
    if(flag==1)
    {
        fcodec->writeEndFrame();//写入结束帧

    }
}
