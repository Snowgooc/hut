/*****************************************************************************
*  @copyright   
*  @file        SmapThread.cpp
*  @brief       简易线程类样例
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
#include "utility/thread/SimpThread.h"
#include <iostream>
#include <unistd.h>



class SmapThread : public SimpThread
{
private:
    int count = 0;

public:
    SmapThread() { };
    virtual ~SmapThread() { };

    virtual void run() 
    {
        sleep(1);
        std::cout << "This is the SmapThread! Times:" << ++count << std::endl;
    };

};



class TestThread : public SimpThread
{
private:
    int count = 0;

public:
    TestThread() { };
    virtual ~TestThread() { };

    virtual void run() 
    {
        sleep(3);
        std::cout << "This is the TestThread!" << ++count << std::endl;
    };

};