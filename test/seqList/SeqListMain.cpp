/***********************************************************
 **文件名:      SeqListMain.cpp
 **功能描述:    顺序表测试程序
 **创建日期:    2022-06-05
 **作者:       
 **版本:        0.1
 **---------------------------------------------------------
 ***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "stllib/SeqList.cpp"

using namespace std;

#define SIZE            10


typedef struct STUDENT_INFO
{
    char name[32];
    int age;
} STUDENT_INFO;


/***********************************************************
 **函数名:      main
 **输入:        int argc -- 入参数
 **输入:        char *argv[] -- 入参列表
 **输出:        int -- 运行结束代码
 **函数功能:    程序主入口
 **作者:        
 **日期:        2022-06-05
 **版本:        0.1
 ***********************************************************/
int main(int argc, char *argv[])
{
    SeqList<STUDENT_INFO> sl(SIZE);
    // 写入7个信息
    for (int i = 0; i < 7; i++)
    {
        STUDENT_INFO temp;
        snprintf(temp.name,sizeof(temp.name), "Tonny%d", i+1);
        temp.age = i+11;
        sl.insert(temp);
    }
    for (int i = 0; i < sl.getLength(); i++)
    {
        STUDENT_INFO temp;
        if (sl.getElem(i+1, temp))
            cout << "name: " << temp.name << " age: " << temp.age << endl;
    }

    // 删除3个信息
    // 删除位置3, 从位置4开始所有数据往前移。顺序表结果:Tonny1,Tonny2,Tonny4,Tonny5,Tonny6,Tonny7
    sl.deleteElem(3);    
    // 删除位置5, 从位置6开始所有数据往前移。顺序表结果:Tonny1,Tonny2,Tonny4,Tonny5,Tonny6
    sl.deleteElem(5);
    // 删除位置5, 从位置6开始所有数据往前移。顺序表结果:Tonny1,Tonny2,Tonny4,Tonny5
    sl.deleteElem(5);
    cout << "deleted 3, 6, 7 localtion element!" << endl;
    for (int i = 0; i < sl.getLength(); i++)
    {
        STUDENT_INFO temp;
        if (sl.getElem(i+1, temp))
            cout << "name: " << temp.name << " age: " << temp.age << endl;
    }


    STUDENT_INFO t1;
    snprintf(t1.name,sizeof(t1.name), "Tonny%d", 3);
    t1.age = 13;
    // 向位置3插入信息。顺序表结果:Tonny1,Tonny2,Tonny3,Tonny4,Tonny5
    sl.insert(t1,3);
    snprintf(t1.name,sizeof(t1.name), "Tonny%d", 8);
    t1.age = 18;
    // 向末尾插入信息。顺序表结果:Tonny1,Tonny2,Tonny3,Tonny4,Tonny5,Tonny8
    sl.insert(t1);
    cout << "inserted 3, 8 localtion element!" << endl;
    for (int i = 0; i < sl.getLength(); i++)
    {
        STUDENT_INFO temp;
        if (sl.getElem(i+1, temp))
            cout << "name: " << temp.name << " age: " << temp.age << endl;
    }

    // 通过复制构造函数构造sl2
    SeqList<STUDENT_INFO> sl2 = sl;
    cout << "copied by Copy Constructor Function" << endl;
    for (int i = 0; i < sl2.getLength(); i++)
    {
        STUDENT_INFO temp;
        if (sl2.getElem(i+1, temp))
            cout << "name: " << temp.name << " age: " << temp.age << endl;
    }

    // sl3顺序表长度设为1，再通过赋值运算符复制sl顺序表
    SeqList<STUDENT_INFO> sl3(1);
    sl3 = sl;
    cout << "copied by Operator = Function" << endl;
    for (int i = 0; i < sl3.getLength(); i++)
    {
        STUDENT_INFO temp;
        if (sl3.getElem(i+1, temp))
            cout << "name: " << temp.name << " age: " << temp.age << endl;
    }



    return 0;
}

