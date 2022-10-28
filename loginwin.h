#ifndef LOGINWIN_H
#define LOGINWIN_H
#include "mainwin.h"
#include <QMessageBox>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QString>
#include <QDebug>
#include <QGridLayout>
#include "database.h"
#include "verificationcodelabel.h"
#include <QStringListIterator>
#include <QMargins>
#include <QHBoxLayout>
#include <QVBoxLayout>
class LoginWin : public QWidget
{
    Q_OBJECT
public:
    explicit LoginWin(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);

    static int loginflag;
    VerificationCodeLabel *LabYanZhengMa;
    QGridLayout *glay;



    Cdatabase *mydb;
    QLabel *LabTitle;//登录界面
    QLabel *LabDvid;
    QLabel *LabUserId;
    QLabel *LabPwd;
    QLabel *LabVfcd;//验证码
    QLabel *LabVfcod;

    QLineEdit *editUserid;
    QLineEdit *editPwd;
    QLineEdit *editVfcd;

    QComboBox *CombDvid;//下拉框

    QPushButton *BtnOk;
    QPushButton *BtnReset;
    QPushButton *BtnCancel;
    QPushButton *BtnShowPwd;

    QAction* passwordAction;



signals:

public slots:
    void GotoLogining();
    void CancelBtn();
    void ShowPwdSlot();
    void ResetBtnSlot();
};

#endif // LOGINWIN_H
