#include "settingswin.h"

settingsWin::settingsWin(QWidget *parent) : QWidget(parent)
{

    //获取指定目录的磁盘情况,直接设置路径即可
    QStorageInfo SD;
    SD.setPath(QDir::currentPath());
    SD.refresh();  //获得最新磁盘信息

    this->setMaximumSize(400,600);//固定尺寸
    this->setMinimumSize(400,600);
    this->setWindowTitle("系统设置");
//滑动条设置
//    lineEdit = new QLineEdit("50 GB");
    lineEdit = new QLineEdit();
    lineEdit->setFocusPolicy(Qt::NoFocus);//不可编辑
    lineEdit->setText(QString("%1 GB").arg(SD.bytesTotal()/1024/1024/1024));
    slider = new QSlider(Qt::Horizontal);	//Qt::Horizontal设置为水平的滑动条
    slider->setMinimum(0);      // 设置滑动条的最小值
    slider->setMaximum(100);   // 设置滑动条的最大值
    slider->setValue(50); // 设置滑动条初始值
    slider->setFixedWidth(220);

    glay=new QGridLayout(this);
    LabTitle=new QLabel("设置界面");
    LabDvid=new QLabel("设备编号");
    LabMemSpc=new QLabel("内存空间");
    LabMemSpc1=new QLabel();
    LabMemSpc1->setText(QString("%1 GB").arg(SD.bytesTotal()/1024/1024/1024));
    LabMemRemain=new QLabel("内存剩余");
    LabVdPath=new QLabel("录像存储");
    LabPixPath=new QLabel("图片存储");
    LabRamind1=new QLabel("检测中...");
    LabRamind2=new QLabel("检测完成");
    LabMemRemain2=new QLabel();
    LabMemRemain2->setText(QString("%1 GB").arg(SD.bytesAvailable()/1024/1024/1024));

    editVdPath=new QLineEdit;
    editPixPath=new QLineEdit;
    editMemSpc=new QLineEdit;
    editMemSpc->setText(QString("%1 GB").arg(SD.bytesTotal()/1024/1024/1024));
    editMemSpc->setFocusPolicy(Qt::NoFocus);
    editMemRemain=new QLineEdit;
    editMemRemain->setText(QString("%1 GB").arg(SD.bytesAvailable()/1024/1024/1024));
    editMemRemain->setFocusPolicy(Qt::NoFocus);

    BtnVdPath=new QPushButton("…");
    BtnPixPath=new QPushButton("…");
    BtnOk=new QPushButton("确定");
    BtnCancel=new QPushButton("取消");
    CombDvid=new QComboBox;
    CombDvid->setEditable(true);
    CombDvid->addItem("HY-2022-001");
    CombDvid->addItem("HY-2022-002");
    CombDvid->addItem("HY-2022-003");
//控件尺寸
    editMemSpc->setFixedWidth(180);
    editMemSpc->setFixedHeight(30);
    editMemRemain->setFixedWidth(180);
    editMemRemain->setFixedHeight(30);
    BtnOk->setFixedHeight(40);
    BtnCancel->setFixedHeight(40);
    CombDvid->setFixedWidth(180);
    CombDvid->setFixedHeight(30);
    editVdPath->setFixedWidth(120);
    editVdPath->setFixedHeight(40);
    editPixPath->setFixedWidth(120);
    editPixPath->setFixedHeight(40);
    BtnVdPath->setFixedWidth(40);
    BtnVdPath->setFixedHeight(40);
    BtnPixPath->setFixedWidth(40);
    BtnPixPath->setFixedHeight(40);
//格栅：控件位置
    glay->addWidget(LabTitle,0,1,1,1,Qt::AlignCenter);
    glay->addWidget(LabDvid,1,0,1,1,Qt::AlignRight);//水平居右，垂直居中
    glay->addWidget(CombDvid,1,1,1,2,Qt::AlignLeft);
    glay->addWidget(LabMemSpc,2,0,1,1,Qt::AlignRight);
    glay->addWidget(editMemSpc,2,1,1,1);
    glay->addWidget(LabMemRemain,3,0,1,1,Qt::AlignRight);
    glay->addWidget(editMemRemain,3,1,1,1,Qt::AlignLeft);
    glay->addWidget(LabVdPath,4,0,1,1,Qt::AlignRight);
    glay->addWidget(editVdPath,4,1,1,2,Qt::AlignLeft);//从第四行第一列开始占据一行两列
    glay->addWidget(BtnVdPath,4,2,1,1,Qt::AlignLeft);//从第四行第一列开始占据一行两列
    glay->addWidget(LabPixPath,5,0,1,1,Qt::AlignRight);
    glay->addWidget(editPixPath,5,1,1,2,Qt::AlignLeft);
    glay->addWidget(BtnPixPath,5,2,1,1,Qt::AlignLeft);
    glay->addWidget(LabRamind1,6,0,1,1,Qt::AlignRight);
    glay->addWidget(LabRamind2,6,2,1,1,Qt::AlignLeft);
    glay->addWidget(BtnOk,7,0,1,1,Qt::AlignRight);
    glay->addWidget(BtnCancel,7,2,1,1,Qt::AlignLeft);

//    glay->addWidget(slider,2,2,1,1,Qt::AlignLeft);
//    glay->addWidget(lineEdit,2,1,1,1);


    connect(BtnVdPath,SIGNAL(clicked(bool)),this,SLOT(on_PathChoose_clicked()));
    connect(BtnPixPath,SIGNAL(clicked(bool)),this,SLOT(on_PathChoose_clicked1()));

    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(setLineEditValue(int)));

    connect(BtnOk, SIGNAL(clicked(bool)), this, SLOT(BtnOkSlot()));
    connect(BtnCancel, SIGNAL(clicked(bool)), this, SLOT(BtnCancelSlot()));


}
void settingsWin::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/bg/11.jpg");
    painter.drawPixmap(0,0,400,600,pix);

}
void settingsWin::Tslider()
{
    qDebug()<<"2121221"<<endl;
}
//槽函数：选择文件存储位置
void settingsWin::on_PathChoose_clicked()
{

    PathName = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 "./",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);

    this->editVdPath->setText(PathName);    //文件名称显示

}


//槽函数：选择文件存储位置
void settingsWin::on_PathChoose_clicked1()
{
//    QDir dir;
    PathName = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 "./",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);

    this->editPixPath->setText(PathName);    //文件名称显示


}
//滑动条与编辑框
void settingsWin::setLineEditValue(int value)
{
    int pos = slider->value();
    QString str = QString("%1").arg(pos)+" GB";

    lineEdit->setText(str);
}

void settingsWin::BtnOkSlot()
{
    if(editVdPath->text()==0||editPixPath->text()==0)
    {
        QMessageBox::information(this,"输入为空","存储路径不能为空，请重新输入");
    }
    else
    {
        mainWin *maiwin=mainWin::getpmainwin();
//        LoginWin *w=new LoginWin();
        maiwin->show();
        this->hide();
    }

}

void settingsWin::BtnCancelSlot()
{
    editPixPath->clear();
    editVdPath->clear();
}
