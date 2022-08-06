/*****************************************************************************
*  @copyright   
*  @file        MeetingMain.h
*  @brief       主函数类
*  @note
*  
*  @author      Snowgooc
*  @version     1.0.0
*  @date        2022-07-30
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
#include <iostream>
#include <unistd.h>
#include "TestObject.h"

using namespace std;



/**
 *  @brief 主函数
 *  @param[in] argc             入参数
 *  @param[in] argv             参数列表
 *  @note
 *  
 *  @return 运行结束代码
 * 
 */
int main(int argc, char *argv[])
{
    // 创建
    // TestObject *tobj = dynamic_cast<TestObject *>(GET_DATAMODEL(TestObject)->create(1));
    GET_DATAMODEL(TestObject)->create(1);

    // 获取
    TestObject *tobj = dynamic_cast<TestObject *>(GET_DATAMODEL(TestObject)->get(1));
    if (tobj)
    {
        cout << "TestObject id is " << tobj->ID() << endl;
    }

    // 删除
    GET_DATAMODEL(TestObject)->cancel();

    return 0;
}



