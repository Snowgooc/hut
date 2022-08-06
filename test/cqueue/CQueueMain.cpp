/*****************************************************************************
*  @copyright   
*  @file        CQueueMain.cpp
*  @brief       容器队列测试
*  @note
*  
*  @author      Snowgooc
*  @version     1.0.0
*  @date        2022-07-03
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
#include <unistd.h>
#include "stllib/CQueue.h"

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
    STUDENT_INFO stinf[20];


    // 设置资源为10个
    CQueue cque(10);
    cout << "初始容量为：" << endl;
    cout << "可用容量:" << cque.getCapacity() << endl;
    cout << "数据数:" << cque.size() << endl;
    cout << endl;


    // 写入12个数据
    cout << "写入12个数据后的容量：" << endl;
    for (int i = 0; i < 12; i++)
    {
        stinf[i].age = 10 + i;
        snprintf((char *)&stinf[i].name, sizeof(stinf[i].name), "Kindy%d", i + 1);
        cque.push(&stinf[i]);
    }
    cout << "可用容量:" << cque.getCapacity() << endl;
    cout << "数据数:" << cque.size() << endl;
    cout << endl;


    // 读取所有数据
    cout << "读取所有数据及容量：" << endl;
    void *dat = cque.pop();
    while (dat)
    {
        STUDENT_INFO *inf = (STUDENT_INFO *)dat;
        cout  << "name: " << inf->name << " age:" << inf->age << endl;
        dat = cque.pop();
    }
    cout << "可用容量:" << cque.getCapacity() << endl;
    cout << "数据数:" << cque.size() << endl;
    cout << endl;


    // 写入20个数据
    cout << "写入20个数据后的容量：" << endl;
    for (int i = 0; i < 20; i++)
    {
        stinf[i].age = 10 + i;
        snprintf((char *)&stinf[i].name, sizeof(stinf[i].name), "Kindy%d", i + 1);
        cque.push(&stinf[i]);
    }
    cout << "可用容量:" << cque.getCapacity() << endl;
    cout << "数据数:" << cque.size() << endl;
    cout << endl;


    // 读取所有数据
    cout << "读取所有数据及容量：" << endl;
    dat = cque.pop();
    while (dat)
    {
        STUDENT_INFO *inf = (STUDENT_INFO *)dat;
        cout  << "name: " << inf->name << " age:" << inf->age << endl;
        dat = cque.pop();
    }
    cout << "可用容量:" << cque.getCapacity() << endl;
    cout << "数据数:" << cque.size() << endl;


    return 0;
}

