/*****************************************************************************
*  @copyright   
*  @file        DObject.h
*  @brief       数据模型测试类
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
#ifndef _TEST_DATAMODEL_TESTOBJECT_H_
#define _TEST_DATAMODEL_TESTOBJECT_H_

#include <stdio.h>
#include "utility/datamodel/DataModel.h"


class TestObject : public DObject
{

public:
    TestObject(int id, void *data = nullptr) : DObject(id, data)
    {
        printf("create TestObject id:%d \n", id);
    }
    virtual ~TestObject()
    {
        printf("delete TestObject id:%d \n", id);
    }

};


DEF_DATAMODEL(TestObject);


#endif /* _TEST_DATAMODEL_TESTOBJECT_H_ */
