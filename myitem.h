#ifndef MYITEM_H
#define MYITEM_H

#include <QObject>
#include <QGraphicsItem>


class MyItem : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    MyItem();
    MyItem(QString filename,int itype,bool islife);//重载构造函数

//属性 ：图元类型、图元状态（是否碰撞、存在）、
    int itype;
    bool islife;
    QString filename;

    QPixmap pix;//图片
//方法

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);

//自定义信号
signals:
    void MyItemcolliding();
//槽
public slots:
   void advance(int phase);
};

#endif // MYITEM_H
