#ifndef REGISTERWIN_H
#define REGISTERWIN_H
#include "loginwin.h"
#include "mainwin.h"
#include <QWidget>
#include <QString>
#include <QDebug>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include "database.h"
#include <QMessageBox>
class registerWin : public QWidget
{
    Q_OBJECT
public:
    explicit registerWin(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    QGridLayout *glay;

    QLabel *LabTitle;//注册界面。
    Cdatabase *mydb;
    QLabel *LabUserId;//用户账号
    QLabel *LabUserName;//用户账号
    QLabel *LabPwd;//密码
    QLabel *LabPwd1;//确认密码

    QLineEdit *editUserId;
    QLineEdit *editUserName;
    QLineEdit *editPwd;
    QLineEdit *editPwd1;

    QPushButton *BtnOk;
    QPushButton *BtnCancel;
signals:

public slots:
    void BtnOkSlot();
    void BtnCancelSlot();
};

#endif // REGISTERWIN_H
