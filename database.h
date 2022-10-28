#ifndef DATABASE_H
#define DATABASE_H
#include <sqlite3.h>

class Cdatabase
{
public:
    ~Cdatabase();
    //数据库类型的指针变量
    sqlite3 *mydb;
    //静态的函数：获取对象指针访问接口
    static Cdatabase *getSignal();
    //不返回结果 exec
    void Exec(char *sql);
    //返回结果 gtab
    int getdata(char *sql,char **&qresult,int &row,int &col);


private:
    Cdatabase(); //私有构造函数：打开数据库
    //私有的静态类对象指针:保存创建好的唯一对象
    static Cdatabase *psignal;
};

#endif // DATABASE_H
