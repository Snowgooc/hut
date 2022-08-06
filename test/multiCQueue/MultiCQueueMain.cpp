/*****************************************************************************
*  @copyright   
*  @file        MultiCQueueMain.cpp
*  @brief       资源复用队列测试
*  @note
*  
*  @author      Snowgooc
*  @version     1.0.0
*  @date        2022-07-06
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
#include "stllib/MultiCQueue.h"

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
    STUDENT_INFO stinf[50];
    int count = 0;

    // 设置资源为10个
    MultiCQueue mtcque(10);


    // 装入10个资源
    for (int i = 0; i < 10; i++)
    {
        mtcque.put(&stinf[count++]);
    }


    // 写入12个数据
    cout << "写入12个数据：" << endl;
    for (int i = 0; i < 12; )
    {
        // 1 获取一个资源
        STUDENT_INFO *inf = (STUDENT_INFO *)mtcque.get();
        if (nullptr == inf)
        {
            // 装入一个新的资源
            mtcque.put(&stinf[count++]);
            continue;
        }
        // 写入数据
        inf->age = 10 + i;
        snprintf((char *)&inf->name, sizeof(inf->name), "Kindy%d", i + 1);
        mtcque.push((void *)inf);
        i++;
    }
    cout << endl;


    // 读取所有数据
    cout << "读取所有数据：" << endl;
    void *dat = mtcque.pop();
    while (dat)
    {
        STUDENT_INFO *inf = (STUDENT_INFO *)dat;
        cout << "name: " << inf->name << " age:" << inf->age << endl;
        mtcque.put(dat);
        dat = mtcque.pop();
    }
    cout << endl;


    cout << "写入5个数据：" << endl;
    for (int i = 0; i < 5; )
    {
        // 1 获取一个资源
        STUDENT_INFO *inf = (STUDENT_INFO *)mtcque.get();
        if (nullptr == inf)
        {
            // 装入一个新的资源
            mtcque.put(&stinf[count++]);
            continue;
        }
        // 写入数据
        inf->age = i;
        snprintf((char *)&inf->name, sizeof(inf->name), "Kindy%d", i);
        mtcque.push((void *)inf);
        i++;
    }
    cout << endl;


    // 读取所有数据
    cout << "读取所有数据：" << endl;
    dat = mtcque.pop();
    while (dat)
    {
        STUDENT_INFO *inf = (STUDENT_INFO *)dat;
        cout << "name: " << inf->name << " age:" << inf->age << endl;
        mtcque.put(dat);
        dat = mtcque.pop();
    }
    cout << endl;


    // 读取资源中的所有数据
    cout << "读取资源中的所有数据" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << "name: " << stinf[i].name << " age:" << stinf[i].age << endl;
    }



    return 0;
}

