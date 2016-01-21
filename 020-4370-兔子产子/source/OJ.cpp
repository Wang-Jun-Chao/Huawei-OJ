#include <stdlib.h>
#include "oj.h"
// 功能：获取第nValue1个月出生多少对兔子
// 输入： nValue1为正整数
// 输出：无
// 返回：第nValue1个月出生多少对兔子

// 这是一个“斐波那契数列”问题
unsigned int GetBirthRabbitNum(unsigned int  nValue1) {

    if(nValue1 < 0) {
        return 0;
    }

    if(nValue1 < 3) {
        return 1;
    }

    return GetBirthRabbitNum(nValue1 - 1) + GetBirthRabbitNum(nValue1 - 2);
}
