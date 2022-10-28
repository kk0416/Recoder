#include "mainwin.h"
mainWin *mainWin::pmainwin=nullptr;
mainWin::mainWin(QWidget *parent) : QWidget(parent)
{
    qDebug()<<11;
    this->setMaximumSize(400,600);//固定尺寸
    this->setMinimumSize(400,600);
    this->setWindowTitle("执法记录仪主界面");

//    QPixmap background(":/image/bg/1.jpg");
//    background=background.scaled(QSize(476,980));

    log1=new LoginWin;
//网格布局
    BtnVideo=new QPushButton;
    BtnVideo->setIconSize(QSize(380,400));
    BtnVideo->setFixedHeight(380);
    BtnVideo->setFixedWidth(400);

    glay=new QGridLayout(this);
    LabTitle=new QLabel("执法记录仪");
    glay->addWidget(LabTitle,0,1,1,1);
    LabTitle->setStyleSheet("QLabel{font:20px;color:99ff99;background-color:rgb(99,f9,f9);}");
    glay->addWidget(BtnVideo,1,0,4,3);
    BtnTakPic=new QPushButton("现场拍照");
    glay->addWidget(BtnTakPic,5,0);
    BtnBakVid=new QPushButton("录像回放");
    glay->addWidget(BtnBakVid,5,1);
    BtnSeePic=new QPushButton("现场图片");
    glay->addWidget(BtnSeePic,5,2);
    BtnSeeLog=new QPushButton("查看日志");
    glay->addWidget(BtnSeeLog,6,0);
    BtnTrsVid=new QPushButton("录像转码");
    glay->addWidget(BtnTrsVid,6,1);
    BtnSettings=new QPushButton("系统设置");
    glay->addWidget(BtnSettings,6,2);
    BtnLogin=new QPushButton("登录");
    BtnReturn=new QPushButton("退出");
    glay->addWidget(BtnLogin,7,0);
    glay->addWidget(BtnReturn,7,0);
    BtnReturn->hide();
    BtnRgs=new QPushButton("注册");
    glay->addWidget(BtnRgs,7,2);

    connect(BtnTakPic,SIGNAL(clicked(bool)),this,SLOT(BtnSlot()));
    connect(BtnSeePic,SIGNAL(clicked(bool)),this,SLOT(BtnSlot()));
    connect(BtnBakVid,SIGNAL(clicked(bool)),this,SLOT(BtnSlot()));
    connect(BtnSeeLog,SIGNAL(clicked(bool)),this,SLOT(BtnSlot()));
    connect(BtnTrsVid,SIGNAL(clicked(bool)),this,SLOT(BtnSlot()));
    connect(BtnLogin,SIGNAL(clicked(bool)),this,SLOT(BtnSlot()));
    connect(BtnRgs,SIGNAL(clicked(bool)),this,SLOT(BtnSlot()));
    connect(BtnSettings,SIGNAL(clicked(bool)),this,SLOT(BtnSlot()));
    connect(BtnReturn,SIGNAL(clicked(bool)),this,SLOT(BtnSlot()));

    //创建解码线程对象
    fdecode *fdec=new fdecode;
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();//获取当前可用摄像头
    if(cameras.size()<=0)
    {
        qDebug()<<"获取摄像头失败!";
    }
     qDebug()<<"获取摄像头cg!";
     QString camera=cameras.at(0).description();
     fdec->setCamera(camera);//将获取到的摄像头传回解码函数
     //QThread::msleep(2000);

    fdec->start();


    connect(fdec,SIGNAL(sendImage(QImage)),this,SLOT(recviceImage(QImage)));


    //创建编码对象 写线程
    fcodec=new fcodec_h264;
    fcodec->codeInit();//初始化
    connect(fdec,SIGNAL(sendYUV(AVFrame*)),this,SLOT(recviceYUV(AVFrame*)));//编码
    connect(fdec,SIGNAL(sendEndFlag(int)),this,SLOT(recviceEndFlag(int)));//结束帧


}
void mainWin::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/bg/11.jpg");
    painter.drawPixmap(0,0,400,600,pix);

    if(!this->img.isNull())
    {

        QImage ima=this->img.scaled(this->BtnVideo->size());
        QPixmap Apixmap=QPixmap::fromImage(img);
        BtnVideo->setIcon(QIcon(Apixmap));
    }

}

mainWin *mainWin::getpmainwin()
{
    mainWin *mainw;
       if(mainw->pmainwin==nullptr)
       {
           mainw->pmainwin=new mainWin();
       }
       return mainw->pmainwin;
}
void mainWin::recviceImage(QImage image)
{
    this->img=image;
    this->update();//接收一张图片，更新一下，重绘界面
}
//触发的函数，实现边播放边编码
void mainWin::recviceYUV(AVFrame *frame)
{
    qDebug()<<"/接收到一帧 就编码：需要一个编码对象->调用编码函数";
    //接收到一帧 就编码：需要一个编码对象->调用编码函数
    fcodec->codecFrame(frame);
}

//触发到这个槽时表明可以写入结束帧
void mainWin::recviceEndFlag(int flag)
{
    if(flag==1)
    {
        fcodec->writeEndFrame();//写入结束帧

    }
    /*重新初始化 一个编码对象*/
}

void mainWin::BtnSlot()
{
    //如何获取按钮的名字
    QPushButton *btntemp=(QPushButton *)sender();
    qDebug()<<btntemp->text();
    if(QString::compare(btntemp->text(),"登录")==0)
    {

        log1->show();
        this->hide();

    }
    else if(QString::compare(btntemp->text(),"注册")==0)
    {

        if(LoginWin::loginflag==1)
        {
            QMessageBox::information(this,"注意","请先退出登录，再进行注册");
        }
        else
        {
            registerWin *rgsw=new registerWin;
            rgsw->show();
            this->hide();
        }

    }

    else if(QString::compare(btntemp->text(),"系统设置")==0)
    {

        settingsWin *setw=new settingsWin;
        setw->show();
        this->hide();
    }

    else if(QString::compare(btntemp->text(),"录像回放")==0)
    {


        if(LoginWin::loginflag==1)
        {
            VideoChooseWin *VdChos=new VideoChooseWin;
            VdChos->show();
            this->hide();
        }
        else
        {
            QMessageBox::information(this,"未登录","请先登录");
            log1->show();
            this->hide();
        }

    }

    else if(QString::compare(btntemp->text(),"现场拍照")==0)
    {

        if(LoginWin::loginflag==1)
        {
            fdec->pixflag=1;
            QMessageBox::information(this,"拍照成功","现场拍照成功");
        }
        else
        {
            QMessageBox::information(this,"未登录","请先登录");
            log1->show();
            this->hide();
        }

    }

    else if(QString::compare(btntemp->text(),"现场图片")==0)
    {


        if(LoginWin::loginflag==1)
        {
           PicToViewWin *picwin=new PicToViewWin;
           picwin->show();
           this->hide();
        }
        else
        {
            QMessageBox::information(this,"未登录","请先登录");
            log1->show();
            this->hide();
        }

    }

    else if(QString::compare(btntemp->text(),"退出")==0)
    {
        LoginWin::loginflag=0;//登录标志位
        this->BtnLogin->show();
        this->BtnReturn->hide();
        QMessageBox::information(this,"退出登录","退出登录成功");
    }



}
