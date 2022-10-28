#ifndef VIDEOCHOOSEWIN_H
#define VIDEOCHOOSEWIN_H

#include <QWidget>
#include <QString>
#include <QDebug>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include "mainwin.h"
#include "videoplaybackwin.h"
#include "calendarkj.h"
#include <QDateTimeEdit>
#include <QListWidget>
//#include "videoplaybackwin.h"
class videoplaybackwin;
class VideoChooseWin : public QWidget
{
    Q_OBJECT
public:
    explicit VideoChooseWin(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    QDateTimeEdit *editdatetime;
    calendarKJ *calenda;//日历1

    QGridLayout *glay;
    QLabel *LabTitle;//录像选择界面
    QLabel *LabDate;//请输入日期
    QListWidget *videowins;//录像列表
    QPushButton *BtnLastPage;
    QPushButton *BtnNextPage;
    QPushButton *BtnOk;
    QPushButton *BtnCancel;

    QToolButton *TlBtnCalendar;
    QAction *ActCalendar;
signals:

public slots:
    void CancelBtnSlot();
    void showCalendarSlot();
    void GetItemName(QListWidgetItem *item);
};

#endif // VIDEOCHOOSEWIN_H
