#ifndef SETTINGSWIN_H
#define SETTINGSWIN_H
#include "mainwin.h"
#include <QWidget>
#include <QString>
#include <QDir>
#include <QFileDialog>
#include <QDateTime>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QDebug>
#include <QGridLayout>
#include<QSlider>		//滑动条头文件
#include<QStorageInfo>
class settingsWin : public QWidget
{
    Q_OBJECT
public:
    explicit settingsWin(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void Tslider();//滑动条
//滑动条
    QSlider *slider;		//定义一个滑动条，在cpp文件的构建函数中设置属性，下列控件同
    QLineEdit *lineEdit;
//文件存储路径
    QString PathName,current_File;
    QDateTime current_File_time;

//控件
    QGridLayout *glay;
    QLabel *LabTitle;//设置界面。
    QLabel *LabDvid;
    QLabel *LabMemSpc;//用滑动条设置
    QLabel *LabMemRemain;
    QLabel *LabMemSpc1;//设置界面。
    QLabel *LabVdPath;
    QLabel *LabPixPath;
    QLabel *LabRamind1;
    QLabel *LabRamind2;
    QLabel *LabMemRemain2;
    QLineEdit *editVdPath;
    QLineEdit *editPixPath;
    QLineEdit *editMemSpc,*editMemRemain;
    QComboBox *CombDvid;//设备编号下拉框
    QPushButton *BtnVdPath;//录像存储路径按钮
    QPushButton *BtnPixPath;
    QPushButton *BtnOk;
    QPushButton *BtnCancel;

signals:

public slots:
    void on_PathChoose_clicked();//选择vd文件存储路径
    void on_PathChoose_clicked1();//选择pic文件存储路径
    void setLineEditValue(int value);//滑动条

    void BtnOkSlot();
    void BtnCancelSlot();
};

#endif // SETTINGSWIN_H
