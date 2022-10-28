#include "pictoviewwin.h"

PicToViewWin::PicToViewWin(QWidget *parent) : QWidget(parent)
{

    mydb=Cdatabase::getSignal();

    this->setMaximumSize(400,600);//固定尺寸
    this->setMinimumSize(400,600);
    this->setWindowTitle("照片查看界面");

    glay=new QGridLayout(this);
    LabTitle=new QLabel("照片列表");
    LabTitle->setStyleSheet("QLabel{font:20px;color:99ff99;background-color:rgb(99,f9,f9);}");
    LabDate=new QLabel("请选择日期");
    LabShowBigPic=new QLabel(this);
    LabShowBigPic->setFixedSize(380,280);
    LabShowBigPic->hide();
/*-----------图片详细信息↓-----------------------*/
    LabShowDetlPic=new QLabel(this);
    LabShowDetlPic->setFixedSize(300,200);
    LabShowDetlPic->hide();

    LabptName=new QLabel("图片名称：");
    LabptTime=new QLabel("图片创建时间：");
    LabptPath=new QLabel("图片路径");
    LabptNameS=new QLabel(this);
    LabptTimeS=new QLabel(this);
    LabptPathS=new QLabel(this);

    LabptName->hide();
    LabptTime->hide();
    LabptPath->hide();
    LabptNameS->hide();
    LabptTimeS->hide();
    LabptPathS->hide();
/*-----------图片详细信息↑-----------------------*/




    BtnReturnList=new QPushButton("返回图片列表");
    BtnReturnList->hide();
    TlBtnReturn = new QToolButton(this);
    ActReturn = new QAction(this);
    ActReturn->setIcon(QIcon(":/image/player/return.png"));
    TlBtnReturn->setIconSize(QSize(48, 48));
    TlBtnReturn->setDefaultAction(ActReturn);

    TlBtnCalendar=new QToolButton(this);//日历图标
    ActCalendar= new QAction(this);
    ActCalendar->setIcon(QIcon(":/image/player/calendar.png"));
    TlBtnCalendar->setIconSize(QSize(48, 48));
    TlBtnCalendar->setDefaultAction(ActCalendar);

    calenda=new calendarKJ(this);
    calenda->hide();
    editdatetime=new QDateTimeEdit(QDate::currentDate(),this);
    editdatetime->setCalendarPopup(true);//日历弹出
    editdatetime->setCalendarWidget(calenda);
    editdatetime->setContextMenuPolicy(Qt::NoContextMenu);
    editdatetime->setFixedSize(150,26);
    editdatetime->setDisplayFormat("yyyy/MM/dd");
    editdatetime->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

//    connect(editdatetime,SIGNAL())

//    calendar=new QCalendarWidget(this);

//    //设置日历的文本格式
//    calendar->setFont(QFont("Timers",8,QFont::Bold));
//    //设置日历的大小
//    calendar->resize(60,60);
    //日历移动
//    calendar->move(0,200);
    //日历隐藏，显示用show（）
//    calendar->hide();

/*-------------------图片列表↓-----------------*/
    videowins = new QListWidget();
    videowins->setViewMode(QListView::IconMode);
    videowins->setMovement(QListView::Static);
    videowins->setResizeMode(QListView::Adjust);

    videowins->setFlow(QListWidget::LeftToRight);
    videowins->setLayoutMode(QListWidget::Batched);
    videowins->setWrapping(true);
    videowins->setIconSize(QSize(140,100));//图片缩略图大小

    //获取视频路径

    QString path = QString(QDir::currentPath()+"/picturpath");
    qDebug()<<path;
    QDir dir(path);
    QStringList moviefilenames;
    moviefilenames << "*.jpg";
    qDebug()<<"1"<<moviefilenames;

    QStringList files = dir.entryList(moviefilenames,QDir::Files|QDir::Readable,QDir::Name);
    qDebug()<<"11"<<files;
    for (int i = 0; i < files.size(); ++i)
    {
        QListWidgetItem *newitem = new QListWidgetItem(QIcon(QPixmap(path+"/"+files.at(i))),files.at(i));
        newitem->setSizeHint(QSize(160,150));
        videowins->addItem(newitem);
    }
/*-------------------图片列表↑-----------------*/

    glay->addWidget(LabTitle,0,1,1,1);
    glay->addWidget(TlBtnReturn,1,0,1,1);
    glay->addWidget(LabDate,2,0,1,1);//日期标签
    glay->addWidget(calenda,3,1,1,2);//日历控件方
    glay->addWidget(TlBtnCalendar,2,4,1,1,Qt::AlignLeft | Qt::AlignVCenter);   //日历弹出按钮
    glay->addWidget(videowins,4,0,4,5);//图片列表
    glay->addWidget(editdatetime,2,1,1,3);//日历控件横

    glay->addWidget(LabShowBigPic,4,0,2,5);//图片放大
    glay->addWidget(LabShowDetlPic,4,0,3,4);//图片详细信息界面的控件↓
    glay->addWidget(LabptName,7,0,1,1);
    glay->addWidget(LabptTime,8,0,1,1);
    glay->addWidget(LabptPath,9,0,1,1);
    glay->addWidget(LabptNameS,7,1,1,1);
    glay->addWidget(LabptTimeS,8,1,1,1);
    glay->addWidget(LabptPathS,9,1,1,1);



//    connect(calendar,SIGNAL(selectionChanged()),this,SLOT(changedata()));
    connect(TlBtnReturn,SIGNAL(clicked(bool)),this,SLOT(ReturnTlbtnSlot()));
    connect(TlBtnCalendar,SIGNAL(clicked(bool)),this,SLOT(showCalendarSlot()));
    connect(videowins,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(GetItemName(QListWidgetItem*)));//单击打印图片名字
    connect(videowins,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(Enlargeimages(QListWidgetItem*)));//双击
    connect(BtnReturnList,SIGNAL(clicked(bool)),this,SLOT(ReturnListSlot()));
}

void PicToViewWin::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/bg/11.jpg");
    painter.drawPixmap(0,0,400,600,pix);

}
//void PicToViewWin::changedata()
//{
//    qDebug()<<"calendar1:"<<this->calendar->selectedDate();//打印当前时间

//    //selectedDate()：获取calendar选中的时间
//    //toString()：由于selectedDate()返回的是一个Qdata类型，你要使用的时候可以转成QString类型
//    //参数"yyyy-MM-dd"是一种固定格式，表示转成年月日字符串，例：2020-12-17
//    //如果"yyyy-MM"，则转成年月，例：2020-12

//    //具体代码：
//    qDebug()<<"calendar2:"<<calendar->selectedDate().toString("yyyy-MM-dd"); //获取选中的年月日
//}

void PicToViewWin::ReturnTlbtnSlot()
{

    mainWin *mainwi=mainWin::getpmainwin();
    mainwi->show();
    this->hide();

}

void PicToViewWin::showCalendarSlot()
{
    qDebug()<<"1"<<endl;
    calenda->show();
    qDebug()<<"11"<<endl;
}


void PicToViewWin::GetItemName(QListWidgetItem *item)
{ 
    qDebug()<<"详细信息图片名字："<<item->text();
    QString imgpath="./picturpath/";
    QString filename=item->text();
    QString imgfinpath=imgpath+filename;
    QImage image(imgfinpath);
    LabShowDetlPic->setPixmap(QPixmap::fromImage(image).scaled(LabShowDetlPic->size()));
    qDebug()<<imgfinpath;

    LabShowDetlPic->show();
    LabptName->show();
    LabptTime->show();
    LabptPath->show();
    LabptNameS->show();
    LabptNameS->setText(filename);
    LabptTimeS->show();
    LabptPathS->show();
    videowins->hide();

    BtnReturnList->show();
    glay->addWidget(BtnReturnList,10,1,1,2);
/*====================获取数据库照片信息↓=========================*/
    char **qresult;
    int row,col;

    QString s=QString("select ptTime,ptPath from tbl_photo where ptName='%1';").arg(filename);
    qDebug()<<s;
    int res=mydb->getdata(const_cast<char *>(s.toStdString().c_str()),qresult,row,col);
    if (res==0)
    {
        if(row==0)
        {
            qDebug()<<"没有该图片的信息！！！"<<endl;
        }
        else
        {

            LabptTimeS->setText(qresult[col]);
            LabptPathS->setText(qresult[col+1]);

        }
    }
/*====================获取数据库照片信息↑=========================*/
}

void PicToViewWin::Enlargeimages(QListWidgetItem *item)
{
    qDebug()<<"放大图片名字："<<item->text();
    QString imgpath="./picturpath/";
    QString filename=item->text();
    QString imgfinpath=imgpath+filename;//拼接路径和获取到的图片名
    QImage image(imgfinpath);
    LabShowBigPic->setPixmap(QPixmap::fromImage(image).scaled(LabShowBigPic->size()));
    qDebug()<<imgfinpath;

    LabShowBigPic->show();
    BtnReturnList->show();
    glay->addWidget(BtnReturnList,6,1,1,2);
    videowins->hide();

}

void PicToViewWin::ReturnListSlot()
{
    LabShowBigPic->hide();
    BtnReturnList->hide();

    LabShowDetlPic->hide();
    LabptName->hide();
    LabptTime->hide();
    LabptPath->hide();
    LabptNameS->hide();
    LabptTimeS->hide();
    LabptPathS->hide();

    videowins->show();
    qDebug()<<"返回列表";
}
