#include "myitem.h"
#include <QPainter>
#include <QDebug>
MyItem::MyItem()
{

}

MyItem::MyItem(QString filename, int itype, bool islife)
{
    pix.load(filename);
    this->itype=itype;
    this->islife=islife;
}

//返回图元边界
QRectF MyItem::boundingRect() const
{
    //qreal penWidth = 1;笔刷用图片替代
    return QRectF(0,0,pix.width(),pix.height());

}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{


    painter->drawPixmap(0,0,pix.width(),pix.height(),pix);//图片显示的位置尺寸


}


void MyItem::advance(int phase)
{
    qDebug()<<"item advance 移动"<<endl;
    if(collidingItems().isEmpty())
    {
        if(this->itype==1)
        {
            this->moveBy(10,0);
        }
        else
        {
            this->moveBy(-10,0);
        }
    }
    else
    {
        qDebug()<<"碰撞到了"<<endl;//碰撞完把定时器关了
        /*--------this->islife=true;--------*/
        //发送信号
        emit MyItemcolliding();
    }



}
