#include "registerwin.h"

registerWin::registerWin(QWidget *parent) : QWidget(parent)
{

    mydb=Cdatabase::getSignal();
    this->setMaximumSize(400,600);//固定尺寸
    this->setMinimumSize(400,600);
    this->setWindowTitle("注册界面");

//控件初始化
    glay=new QGridLayout(this);
    LabTitle=new QLabel("注册界面");
    LabUserId=new QLabel("警员编号");
    LabUserName=new QLabel("警员姓名");
    LabPwd=new QLabel("密码");
    LabPwd1=new QLabel("确认密码");
    editUserId=new QLineEdit;
    editUserId->setPlaceholderText(QStringLiteral("长度6-10的数字或英文字母"));
    editUserName=new QLineEdit;
//    editUserName->setPlaceholderText(QStringLiteral("长度6-10的数字或英文字母"));
    editPwd=new QLineEdit;
    editPwd->setEchoMode(QLineEdit::Password);
    editPwd->setPlaceholderText(QStringLiteral("长度6-10的数字或英文字母"));
    editPwd1=new QLineEdit;
    editPwd1->setEchoMode(QLineEdit::Password);
    editPwd1->setPlaceholderText(QStringLiteral("请再次输入密码"));

    BtnOk=new QPushButton("确定");
    BtnCancel=new QPushButton("取消");
//控件尺寸
    BtnOk->setFixedHeight(40);
    BtnCancel->setFixedHeight(40);

    editPwd->setFixedWidth(240);
    editPwd->setFixedHeight(30);
    editUserId->setFixedWidth(240);
    editUserId->setFixedHeight(40);
    editUserName->setFixedWidth(240);
    editUserName->setFixedHeight(40);
    editPwd1->setFixedWidth(240);
    editPwd1->setFixedHeight(40);

//格栅布局：控件位置
    glay->addWidget(LabTitle,0,1,1,1);
    glay->addWidget(LabUserId,1,0,1,1,Qt::AlignRight | Qt::AlignVCenter);//水平居右，垂直居中
    glay->addWidget(LabUserName,2,0,1,1,Qt::AlignRight | Qt::AlignVCenter);//水平居右，垂直居中
    glay->addWidget(LabPwd,3,0,1,1,Qt::AlignRight | Qt::AlignVCenter);
    glay->addWidget(LabPwd1,4,0,1,1,Qt::AlignRight | Qt::AlignVCenter);
    glay->addWidget(editUserId,1,1,1,2);//从第一行第一列开始占据一行两列
    glay->addWidget(editUserName,2,1,1,2);
    glay->addWidget(editPwd,3,1,1,2);
    glay->addWidget(editPwd1,4,1,1,2);
    glay->addWidget(BtnOk,5,0,1,1,Qt::AlignRight | Qt::AlignVCenter);
    glay->addWidget(BtnCancel,5,2,1,1,Qt::AlignLeft | Qt::AlignVCenter);


    connect(BtnOk, SIGNAL(clicked(bool)), this, SLOT(BtnOkSlot()));
    connect(BtnCancel, SIGNAL(clicked(bool)), this, SLOT(BtnCancelSlot()));

}

void registerWin::BtnOkSlot()
{
//验证成功后

    QString nUserId=editUserId->text();
    QString nUserName=editUserName->text();
    QString npassword=editPwd->text();
    QString npassword1=editPwd1->text();

    qDebug()<<"新注册用户编号："<<nUserId;
    qDebug()<<"新注册用户名："<<nUserName;
    qDebug()<<"新注册用户密码："<<npassword;
    qDebug()<<"新注册确认用户密码："<<npassword1;

    if(nUserId==""||nUserName==""||npassword=="")
    {
        QMessageBox::warning(this,"","输入不能为空！");
    }
    else if(QString::compare(npassword1,npassword)!=0)
    {
         QMessageBox::warning(this,"密码不一致","密码不一致，请重新输入");
    }
    else
    {
        QString s=QString("insert into Tbl_user(UserId,UserName,userPwd) values('%1','%2','%3');")
                .arg(nUserId).arg(nUserName).arg(npassword);
        qDebug()<<s;
        mydb->Exec(const_cast<char *>(s.toStdString().c_str()));
        QMessageBox::information(this,"成功","注册成功，返回登录界面");
        LoginWin *loginw=new LoginWin;
        loginw->show();
        this->hide();
    }

}
void registerWin::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/bg/11.jpg");
    painter.drawPixmap(0,0,400,600,pix);

}
void registerWin::BtnCancelSlot()
{
    mainWin *maiwin=mainWin::getpmainwin();
    maiwin->show();
    this->hide();
}
