#include "database.h"
#include <QDebug>
//静态成员初始化
Cdatabase *Cdatabase::psignal=nullptr;
Cdatabase::Cdatabase()
{
    qDebug()<<"111"<<endl;
    //数据成员 数据库：直接用
    mydb=nullptr;
    //打开数据库的API，用变量接收返回值
    int res=sqlite3_open("data/recoder1.db",&mydb);
    //判断数据库是否打开成功
    if(res==0)
    {
        qDebug()<<"open db success！！！"<<endl;
    }
    else
    {
        //错误代码的查看
        qDebug()<<sqlite3_errcode(mydb)<<endl;
        //错误原因的输出，显示
        qDebug()<<sqlite3_errmsg(mydb)<<endl;
    }
}

Cdatabase::~Cdatabase()
{
    //关闭数据库
    sqlite3_close(mydb);
}

Cdatabase *Cdatabase::getSignal()
{
    Cdatabase c;

    if(c.psignal==nullptr)
    {
        c.psignal=new Cdatabase();
    }
    return c.psignal;
}

void Cdatabase::Exec(char *sql)
{
    char *errmsg;
    int res=sqlite3_exec(mydb,sql,nullptr,nullptr,&errmsg);
    //判断
    if(res==0)
    {
         qDebug()<<"sql exec success！！！"<<endl;
    }
    else
    {
        qDebug()<<sqlite3_errmsg(mydb)<<endl;
    }
}

int Cdatabase::getdata(char *sql, char **&qresult, int &row, int &col)
{
    char *errmsg;
    int res=sqlite3_get_table(mydb,sql,&qresult,&row,&col,&errmsg);
    if(res==0)
    {
         return 0;
    }
    else
    {
        qDebug()<<sqlite3_errmsg(mydb)<<endl;
        return -1;
    }
}


