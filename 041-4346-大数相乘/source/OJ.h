#ifndef __OJ_H__
#define __OJ_H__

#include <string>

using namespace std;
/*****************************************************************************
 Prototype    : multiply
 Description  : 两个任意长度的长整数相乘, 输出结果
 Input Param  : 
                const std::string strMultiplierA  乘数A
                const std::string strMultiplierB  乘数B
 Output       : 
                std::string strRst            乘法结果
 Return Value : 
                int                       0  正确  
                                         -1  异常
*****************************************************************************/
int multiply (const std::string strMultiplierA,const std::string strMultiplierB, std::string &strRst);

#endif
