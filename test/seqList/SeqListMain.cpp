/*****************************************************************************
*  @copyright   
*  @file        SeqListMain.cpp
*  @brief       顺序表测试程序
*  @note
*  
*  @author      Snowgooc
*  @version     1.0.0
*  @date        2022-06-26
*  
*----------------------------------------------------------------------------
*  Remark         : Description
*----------------------------------------------------------------------------
*  Change History :
*  <Date>     | <Version> | <Author>       | <Description>
*----------------------------------------------------------------------------
*  
*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "stllib/SeqList.h"

using namespace std;
using namespace com_stl;


typedef struct STUDENT_INFO
{
    char        name[32];
    int         age;
} STUDENT_INFO;



/**  
 *  @brief  程序主入口
 *  @param[in] argc         入参个数
 *  @param[in] argv         入参列表
 *  @note
 *  
 *  @return 
 *  运行结束状态
 *  
 */
int main(int argc, char *argv[])
{
    // ------------------------------------------------
    // 1. 常规构造
    cout << "1. 常规构造" << endl;
    SeqList<STUDENT_INFO> sl(10);
    // 写入7个信息
    for (int i = 0; i < 7; i++)
    {
        STUDENT_INFO temp;
        snprintf(temp.name,sizeof(temp.name), "Tonny%d", i+1);
        temp.age = i+11;
        sl.insert(temp);
    }
    for (int i = 0; i < sl.size(); i++)
    {
        cout << "name: " << sl.at(i).name << " age: " << sl.at(i).age << endl;
    }


    // ------------------------------------------------
    // 2. 删除3个信息
    cout << "2. 删除3个信息" << endl;
    // 删除位置3, 从位置4开始所有数据往前移。顺序表结果:Tonny1,Tonny2,Tonny4,Tonny5,Tonny6,Tonny7
    sl.delElem(3);    
    // 删除位置5, 从位置6开始所有数据往前移。顺序表结果:Tonny1,Tonny2,Tonny4,Tonny5,Tonny6
    sl.delElem(5);
    // 删除位置5, 从位置6开始所有数据往前移。顺序表结果:Tonny1,Tonny2,Tonny4,Tonny5
    sl.delElem(5);
    cout << "deleted 3, 6, 7 localtion element!" << endl;
    for (int i = 0; i < sl.size(); i++)
    {
        cout << "name: " << sl.at(i).name << " age: " << sl.at(i).age << endl;
    }


    // ------------------------------------------------
    // 3. 插入两个数据
    cout << "3. 插入两个数据" << endl;
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
    for (int i = 0; i < sl.size(); i++)
    {
        cout << "name: " << sl.at(i).name << " age: " << sl.at(i).age << endl;
    }


    // ------------------------------------------------
    // 4. 通过复制构造函数构造
    cout << "4. 通过复制构造函数构造" << endl;
    SeqList<STUDENT_INFO> sl2 = sl;
    cout << "copied by Copy Constructor Function" << endl;
    for (int i = 0; i < sl2.size(); i++)
    {
        cout << "name: " << sl2.at(i).name << " age: " << sl2.at(i).age << endl;
    }


    // ------------------------------------------------
    // 5. sl3顺序表长度设为1，再通过赋值运算符复制sl顺序表
    cout << "5. 通过赋值运算符" << endl;
    SeqList<STUDENT_INFO> sl3(1);
    sl3 = sl;
    cout << "copied by Operator= Function" << endl;
    for (int i = 0; i < sl3.size(); i++)
    {
        cout << "name: " << sl3[i].name << " age: " << sl3[i].age << endl;
    }


    // ------------------------------------------------
    // 6. 通过移动构造
    cout << "6. 通过移动构造" << endl;
    SeqList<STUDENT_INFO> sl4 = move(sl3);      // 这里使用移动构造
    // SeqList<STUDENT_INFO> sl7(move(sl2));      // 这里使用移动构造
    cout << "copied by Move Constructor Function" << endl;
    for (int i = 0; i < sl4.size(); i++)
    {
        cout << "name: " << sl4[i].name << " age: " << sl4[i].age << endl;
    }


    // ------------------------------------------------
    // 7. 通过移动赋值
    cout << "7. 通过移动赋值" << endl;
    SeqList<STUDENT_INFO> sl5(1);
    sl5 = move(sl4);                    // 这里使用移动赋值函数
    sl5.delElem(sl5.size());
    cout << "copied by Move Operator= Function" << endl;
    for (int i = 0; i < sl5.size(); i++)
    {
        cout << "name: " << sl5[i].name << " age: " << sl5[i].age << endl;
    }



    return 0;
}

