#include "myview.h"
#include <QPalette>
MyView::MyView()
{
/*---居中显示
    QDesktopWidget *desktop = QApplication::desktop();
    move((desktop->width()-this->width())/2,(desktop->height()-this->height())/2);
----*/

//    QPalette palette; //背景颜色
//    palette.setBrush(QPalette::Background,QBrush(Qt::black));
//    this->setPalette(palette);
//    this->setAutoFillBackground(true);


    //背景视图
    QPixmap background(":/image/bg/8.jpg");
    background=background.scaled(QSize(620,950));
    this->setBackgroundBrush(QBrush(background));
    this->setMaximumSize(400,600);//固定尺寸
    this->setMinimumSize(400,600);
//    this->LabTitle=new QLabel("智能执法记录仪");
//    LabTitle->setGeometry(0,0,10,5);//位置和
    pScene=new QGraphicsScene;
    pScene->setSceneRect(190,110,380,560);//设置场景尺寸，解决界面下方有滑动条的bug

    item1=new MyItem("://image/police/1.png",1,false);//定义图元
    item2=new MyItem("://image/police/2.png",2,false);

    item1->setPos(this->width()/4+4,this->height()/2); //图元位置
    item2->setPos(this->width()-10,this->height()/2);

    pScene->addItem(item1);//图元添加到场景
    pScene->addItem(item2);
    this->setScene(pScene);//场景通过视图显示

    time1 = new QTimer(this);//定时器：实现移动
    connect(time1, SIGNAL(timeout()), pScene, SLOT(advance()));//advance 图元移动 在图元类定义
    time1->start(500);
 /*--------
    //再来一个定时器检测是否碰撞到
    time2 = new QTimer(this);
    connect(time2, SIGNAL(timeout()), this, SLOT(ItemStopSlot()));//advance 图元移动 在图元类定义
    time2->start(1000);
    ---------------*/
    //自定义信号
    connect(item1, SIGNAL(MyItemcolliding()), this, SLOT(ItemStopSlot()));//advance 图元移动 在图元类定义

}
//背景图
//void MyView::paintEvent(QPaintEvent *)
//{

//    QPainter painter(this);
//    QPixmap pix;
//    pix.load(":/image/bg/11.jpg");
//    painter.drawPixmap(0,0,620,950,pix);

//}

void MyView::ItemStopSlot()
{
//    if(item1->islife==true)//如果碰撞到，停止移动（计时器1停止），出现界面
//    {

    qDebug()<<"11"<<endl;
        time1->stop();

        settingsWin *sw=new settingsWin();
//        mainWin *p=mainWin::getpmainwin();
        sw->show();
        this->hide();
 /*----
        item1->islife==false;
        time2->stop();
        --*/
//    }
}
