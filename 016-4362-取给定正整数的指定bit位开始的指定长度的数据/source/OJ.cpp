
#include "OJ.h"

/*
Description
         取给定正整数的指定bit位开始的指定长度的数据。bit位从右向左从0开始计算。
Prototype
         unsigned int GetBitsValue(unsigned int input, unsigned int startbit, unsigned int bitlen)
Input Param
         input      输入的整数
         startbit   需要获取的开始bit
         bitlen     需要获取的bit长度
Output Param
         无
Return Value
		 对应的bit取值
*/

unsigned int GetBitsValue(unsigned int input, unsigned int startbit, unsigned int bitlen) {

    unsigned int mask = 0;
    unsigned int endbit =startbit + 1 - bitlen;
    mask = (~mask) << (bitlen);

    input = input >> endbit;
    input = input & (~mask);

    return input;
}
