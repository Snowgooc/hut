/*****************************************************************************
*  @copyright   
*  @file        SimpThreadMain.cpp
*  @brief       简易线程类测试
*  @note
*  
*  @author      Snowgooc
*  @version     1.0.0
*  @date        2022-07-10
*  
*----------------------------------------------------------------------------
*  Remark         : Description
*----------------------------------------------------------------------------
*  Change History :
*  <Date>     | <Version> | <Author>       | <Description>
*----------------------------------------------------------------------------
*  
*****************************************************************************/
#include <iostream>
#include <unistd.h>
#include <signal.h>
#include "SmapThread.h"

using namespace std;

bool isAlive = false;


void hand(int val)
{
    isAlive = false;
}


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
    // 设置信号处理，为了使线程安全退出
    signal(SIGINT, hand);


    SmapThread st;
    TestThread tt;

    // 启动线程
    tt.start();
    st.start();

    isAlive = true;
    while (isAlive)
    {
        sleep(10);
    }

    // 关闭线程
    st.stop();
    tt.stop();

    return 0;
}
