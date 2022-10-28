#ifndef PICTOVIEWWIN_H
#define PICTOVIEWWIN_H
#include <QCalendarWidget>//日历
#include <QWidget>
#include <QDebug>
#include <QToolButton>
#include <QLabel>
#include <QGridLayout>
#include <QAction>
#include <QListWidget>
#include "mainwin.h"
#include "calendarkj.h"
#include <QDateTimeEdit>
#include <QPushButton>
#include "database.h"
//lab标题 返回按钮 日期控件  图片文件列表  翻页
class PicToViewWin : public QWidget
{
    Q_OBJECT
public:
    explicit PicToViewWin(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    Cdatabase *mydb;

    QDateTimeEdit *editdatetime;
    calendarKJ *calenda;//日历1
    QListWidget *videowins;
//    QCalendarWidget *calendar;//日历
    QGridLayout *glay;
    QLabel *LabTitle;//图片查看界面
    QLabel *LabDate;
    QLabel *LabShowBigPic;//查看放大的图片
    QLabel *LabShowDetlPic;//查看图片详细信息
    QToolButton *TlBtnReturn;
    QToolButton *TlBtnCalendar;
    QAction *ActReturn;
    QAction *ActCalendar;
    QPushButton *BtnReturnList;

    QLabel *LabptName,*LabptTime,*LabptPath;
    QLabel *LabptNameS,*LabptTimeS,*LabptPathS;

signals:

public slots:
//    void changedata();//日历点击
    void ReturnTlbtnSlot();//返回上个界面
    void showCalendarSlot();
    void GetItemName(QListWidgetItem *item);
    void Enlargeimages(QListWidgetItem *item);//Enlargeimages
    void ReturnListSlot();//返回列表
};

#endif // PICTOVIEWWIN_H
