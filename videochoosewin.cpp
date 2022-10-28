#include "videochoosewin.h"
//#include "fdecode.h"
#include "fdecodeplay.h"
VideoChooseWin::VideoChooseWin(QWidget *parent) : QWidget(parent)
{

    this->setMaximumSize(400,600);//固定尺寸
    this->setMinimumSize(400,600);
    this->setWindowTitle("录像选择界面");

    glay=new QGridLayout(this);
    LabTitle=new QLabel("列表");
    LabTitle->setStyleSheet("QLabel{font:30px;color:99ff99;background-color:rgb(99,f9,f9);}");
    LabDate=new QLabel("请选择日期");
    BtnLastPage=new QPushButton("上一页");
    BtnNextPage=new QPushButton("下一页");
    BtnOk=new QPushButton("确定");
    BtnCancel=new QPushButton("取消");
/*===========日历↓===========================*/
    calenda=new calendarKJ(this);
    calenda->hide();
    editdatetime=new QDateTimeEdit(QDate::currentDate(),this);
    editdatetime->setCalendarPopup(true);//日历弹出
    editdatetime->setCalendarWidget(calenda);
    editdatetime->setContextMenuPolicy(Qt::NoContextMenu);
    editdatetime->setFixedSize(150,26);
    editdatetime->setDisplayFormat("yyyy/MM/dd");
    editdatetime->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    TlBtnCalendar=new QToolButton(this);//日历图标
    ActCalendar= new QAction(this);
    ActCalendar->setIcon(QIcon(":/image/player/calendar.png"));
    TlBtnCalendar->setIconSize(QSize(48, 48));
    TlBtnCalendar->setDefaultAction(ActCalendar);
/*===========日历↑===========================*/

/*-------------------视频列表↓-----------------*/
    videowins = new QListWidget();
    videowins->setViewMode(QListView::IconMode);
    videowins->setMovement(QListView::Static);
    videowins->setResizeMode(QListView::Adjust);

    videowins->setFlow(QListWidget::LeftToRight);
    videowins->setLayoutMode(QListWidget::Batched);
    videowins->setWrapping(true);
    videowins->setIconSize(QSize(60,30));//图片缩略图大小

    //获取视频路径

    QString path = QString(QDir::currentPath()+"/videopath");
    qDebug()<<path;
    QDir dir(path);
    QStringList moviefilenames;
    moviefilenames << "*.h264";
    qDebug()<<moviefilenames;

    QStringList files = dir.entryList(moviefilenames,QDir::Files|QDir::Readable,QDir::Name);
    qDebug()<<files;
    for (int i = 0; i < files.size(); ++i)
    {
        QListWidgetItem *newitem = new QListWidgetItem(QIcon(QPixmap(path+"/"+files.at(i))),files.at(i));
        newitem->setSizeHint(QSize(350,80));
        videowins->addItem(newitem);
    }

 /*-------------------视频列表↑-----------------*/

    BtnLastPage->setFixedHeight(30);
    BtnNextPage->setFixedHeight(30);
    BtnOk->setFixedHeight(40);
    BtnCancel->setFixedHeight(40);

    glay->addWidget(LabTitle,0,1,1,1,Qt::AlignVCenter);
    glay->addWidget(LabDate,1,0,1,1);
    glay->addWidget(calenda,2,1,1,2);
    glay->addWidget(TlBtnCalendar,1,3,1,1,Qt::AlignLeft | Qt::AlignVCenter);
//    glay->addWidget(videowins,4,0,4,5);
    glay->addWidget(editdatetime,1,1,1,2);
    glay->addWidget(videowins,3,0,4,5);//视频列表
//    glay->addWidget(BtnLastPage,7,0,1,1);
//    glay->addWidget(BtnNextPage,7,2,1,1);
    glay->addWidget(BtnOk,7,0,1,1);
    glay->addWidget(BtnCancel,7,2,1,1,Qt::AlignLeft | Qt::AlignVCenter);

    connect(TlBtnCalendar,SIGNAL(clicked(bool)),this,SLOT(showCalendarSlot()));
    connect(BtnCancel,SIGNAL(clicked(bool)),this,SLOT(CancelBtnSlot()));
    connect(videowins,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(GetItemName(QListWidgetItem*)));

}
void VideoChooseWin::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/bg/11.jpg");
    painter.drawPixmap(0,0,400,600,pix);

}
//返回主界面
void VideoChooseWin::CancelBtnSlot()
{
    mainWin *mainWn=mainWin::getpmainwin();
    mainWn->show();
    this->hide();
}
//点击日历按钮显示日历列表
void VideoChooseWin::showCalendarSlot()
{
    qDebug()<<"1"<<endl;
    calenda->show();
    qDebug()<<"11"<<endl;
}

void VideoChooseWin::GetItemName(QListWidgetItem *item)
{

    qDebug()<<item->text();

    fdecodeplay::playflag=1;//播放标志位
    fdecodeplay::setPicname(item->text());//将所选视频名传入解码run函数
    this->hide();
    VideoPlaybackWin *vpb=new VideoPlaybackWin;
    vpb->show();

}
