#include "loginwin.h"
int LoginWin::loginflag=0;
LoginWin::LoginWin(QWidget *parent) : QWidget(parent)
{

    mydb=Cdatabase::getSignal();

    this->setMaximumSize(400,600);//固定尺寸
    this->setMinimumSize(400,600);
    this->setWindowTitle("登录界面");

    QPixmap background(":/image/bg/11.jpg");
    background=background.scaled(QSize(400,600));
//控件初始化

    LabYanZhengMa=new VerificationCodeLabel;
    glay=new QGridLayout(this);
    LabTitle=new QLabel("登录界面");
    LabDvid=new QLabel("设备编号");
    LabUserId=new QLabel("警员编号");
    LabPwd=new QLabel("密码");
    LabVfcd=new QLabel("验证码");

    editUserid=new QLineEdit;
    editUserid->setPlaceholderText(QStringLiteral("请输入警员编号"));
/*
    editUserid->setStyleSheet("QLineEdit {border: 2px solid #EEE;border-radius: 4px;background-color:#FFFCEC;padding-right: 14px;}"
                              "QLineEdit:focus {border-color: #bbbec4;}"
                              "QLineEdit QPushButton {width:  16px;height: 16px;qproperty-flat: true;margin-right: 4px;border: none;border-width: 0;border-image: url(:/1.png) 0 0 0 0 stretch stretch;}"
                              );
*/
    editPwd=new QLineEdit;
    editPwd->setEchoMode(QLineEdit::Password);
//    editPwd->setPlaceholderText(QStringLiteral("长度6-10的数字或英文字母"));
/*
    editPwd->setEchoMode(QLineEdit::PasswordEchoOnEdit);    //输入时显示数字，失去焦点时显示圆点
    editPwd->setStyleSheet("QLineEdit {border: 2px solid #EEE;background-color:#bbbec4;border-radius: 4px;padding-right: 14px;}"
                                "QLineEdit:focus {border-color: #bbbec4;}"
                                 );
    editPwd->setStyleSheet("background-color:rgba(0,255,255,255)");
*/
    editVfcd=new QLineEdit;

    BtnOk=new QPushButton("确定");
    BtnReset=new QPushButton("清空");
    BtnCancel=new QPushButton("取消");
    BtnShowPwd=new QPushButton(this);

/*小眼睛 鼠标上面闭眼  移开 睁眼*/
    BtnShowPwd->setCursor(Qt::PointingHandCursor);
    BtnShowPwd->setFixedSize(22,22);
    BtnShowPwd->setToolTip(QStringLiteral("密码可见"));
    BtnShowPwd->setStyleSheet("QPushButton{border-image:url(:/image/Login/眼睛_显示_o.png);background:transparent;}\
                                   QPushButton::hover{border-image:url(:/image/Login/眼睛_显示_o.png)}\
                                   QPushButton::pressed{border-image:url(:/image/Login/眼睛_显示_o.png)}");
    QMargins margins=editPwd->textMargins();
    editPwd->setTextMargins(margins.left(),margins.top(),BtnShowPwd->width(),margins.bottom());
    editPwd->setPlaceholderText(QStringLiteral("请输入密码"));

    CombDvid=new QComboBox;
    CombDvid->setEditable(true);
    CombDvid->addItem("HY-2022-001");
    CombDvid->addItem("HY-2022-002");
    CombDvid->addItem("HY-2022-003");

//控件尺寸
    BtnOk->setFixedHeight(40);
    BtnCancel->setFixedHeight(40);
    BtnReset->setFixedHeight(40);

    CombDvid->setFixedWidth(240);
    CombDvid->setFixedHeight(30);
    editUserid->setFixedWidth(240);
    editUserid->setFixedHeight(40);
    editPwd->setFixedWidth(240);
    editPwd->setFixedHeight(40);
    editVfcd->setFixedWidth(120);
    editVfcd->setFixedHeight(40);
//格栅：控件位置
//    LabTitle ->setAlignment(Qt::AlignVCenter);

    glay->addWidget(LabTitle,0,1,1,1);
    glay->addWidget(LabDvid,1,0,1,1);//水平居右，垂直居中
    glay->addWidget(LabUserId,2,0,1,1);
    glay->addWidget(LabPwd,3,0,1,1);
    glay->addWidget(LabVfcd,4,0,1,1);
    glay->addWidget(editUserid,2,1,1,2);//从第四行第一列开始占据一行两列
    glay->addWidget(editPwd,3,1,1,2);
    glay->addWidget(BtnShowPwd,3,2,1,1);
    glay->addWidget(editVfcd,4,1,1,2);
    glay->addWidget(LabYanZhengMa,4,2,1,1);
    glay->addWidget(CombDvid,1,1,1,2);
    glay->addWidget(BtnOk,5,0,1,1);
    glay->addWidget(BtnCancel,5,1,1,1);
    glay->addWidget(BtnReset,5,2,1,1);

    // 设置水平间距
    glay->setHorizontalSpacing(8);
    // 设置垂直间距
    glay->setVerticalSpacing(13);
    // 设置外间距
//    glay->setContentsMargins(90, 40, 100, 100);//左上右下
    setLayout(glay);

//    QVBoxLayout *BLayout=new QVBoxLayout(this);
//    BLayout->addWidget(LabTitle);
//    BLayout->addLayout(glay);
//    BLayout->setStretchFactor(LabTitle,1);
//    BLayout->setStretchFactor(glay,1);


    //创建按下按钮和相应动作
    connect(BtnOk,SIGNAL(clicked(bool)),this,SLOT(GotoLogining()));
    connect(BtnCancel,SIGNAL(clicked(bool)),this,SLOT(CancelBtn()));
    connect(BtnShowPwd,SIGNAL(clicked(bool)),this,SLOT(ShowPwdSlot()));
    connect(BtnReset,SIGNAL(clicked(bool)),this,SLOT(ResetBtnSlot()));

}
//背景图
void LoginWin::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/bg/11.jpg");
    painter.drawPixmap(0,0,400,600,pix);

}

void LoginWin::GotoLogining()
{
    //测试是否连接成功:连接成功的话，点击按钮下方会打印
    qDebug()<<"点击登录按钮";

    //判断用户名密码
    //先定义临时变量

    QString UserId=editUserid->text();
    QString password=editPwd->text();
    QString yzm=editVfcd->text();

//    QString str(LabYanZhengMa->verificationCode);
    qDebug()<<"UserId"<<UserId;
    qDebug()<<"password"<<password;

    QString s=QString("select * from Tbl_user where UserId ='%1' and userPwd = '%2'")
            .arg(UserId).arg(password);



    qDebug()<<s;
    char **qresult;
    int row=0,col=0;
    char *errmsg;
   // qDebug()<<sql<<endl;

    //调用返回结果的函数
     qDebug()<<const_cast<char *>(s.toStdString().c_str());
    int res=mydb->getdata(const_cast<char *>(s.toStdString().c_str()),qresult,row,col);
    if(res==0)
    {
        if(row==0)
        {
            qDebug()<<"没有你要查询的结果！！！"<<endl;

            if(UserId==0||password==0)
            {
                 QMessageBox::information(this,"输入为空","输入不能为空");
            }
            else
            {
                //弹出消息框
                QMessageBox::information(this,"登录错误","用户名/密码错误");
                editPwd->clear();
                editUserid->clear();
                editVfcd->clear();
            }

        }

        else if(QString::compare(yzm,LabYanZhengMa->v)!=0)
        {

            qDebug()<<"验证码错误"<<endl;
            qDebug()<<"验证码："<<LabYanZhengMa->v;
            //弹出消息框
            QMessageBox::information(this,"验证码错误","验证码错误，请耐心地多试几遍~");
            editVfcd->clear();

        }
        else
        {
             qDebug()<<"登录验证成功";
             LoginWin::loginflag=1;//登录标志位
             mainWin *mainWn=mainWin::getpmainwin();
             mainWn->show();
             this->hide();
             mainWn->BtnLogin->hide();
             mainWn->BtnReturn->show();
             QMessageBox::information(this,"登录验证成功","登录验证成功");
        }
    }

}

void LoginWin::CancelBtn()
{
    editPwd->clear();
    editUserid->clear();
    editVfcd->clear();
    mainWin *mainWn=mainWin::getpmainwin();
    mainWn->show();
    this->hide();
}

void LoginWin::ShowPwdSlot()
{
    editPwd->setEchoMode(QLineEdit::Normal);
}

void LoginWin::ResetBtnSlot()
{
    editPwd->clear();
    editUserid->clear();
    editVfcd->clear();
}


