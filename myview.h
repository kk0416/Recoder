#ifndef MYVIEW_H
#define MYVIEW_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "myitem.h"
#include <QTimer>
#include "settingswin.h"
#include "mainwin.h"
#include <QDesktopWidget>
#include <QApplication>
#include "fdecode.h"
#include <QLabel>
class MyView :public QGraphicsView
{
    Q_OBJECT
public:
    MyView();

//    void paintEvent(QPaintEvent *);

    QGraphicsScene *pScene;
    //定义图元:图元放到场景上，通过视图显示
    MyItem *item1;
    MyItem *item2;
    QTimer *time1;
    QTimer *time2;

    QLabel *LabTitle;
public slots:
    void ItemStopSlot();//移动停止
};

#endif // MYVIEW_H
