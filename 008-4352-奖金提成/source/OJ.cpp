#include <stdlib.h>
#include "oj.h"


/*
功能:
	企业发放的奖金根据利润提成。
	利润低于或等于100000元的，奖金可提10%；
	利润高于100000元，低于200000元（100000<I≤200000）时；
	低于100000元的部分按10％提成；
	高于100000元的部分，可提成 7.5%；
	200000<I≤400000时，低于200000元部分仍按上述办法提成，（下同）；
	高于200000元的部分按5％提成；
	400000<I≤600000元时，高于400000元的部分按3％提成；
	600000<I≤1000000时，高于600000元的部分按1.5%提成；
	I>1000000时，超过1000000元的部分按1%提成。
	从键盘输入当月利润I,求应发奖金总数

输入:
	一个整数，当月利润 x

输出:
	无

返回:
	一个整数，奖金

*/

size_t Bonus(size_t profit) {

    size_t result = 0;

    // 利润低于或等于100000元的，奖金可提10%；
    if(profit <= 100000) {
        return (size_t)(profit*0.1);
    }

    result += 10000;

    // 100000<profit<=200000，可提成 7.5%
    if(profit <= 200000) {
        result += (size_t)((profit - 100000)*0.075);
        return result;
    }

    result += 7500;

    // 200000<prfit≤400000，高于200000元的部分按5％提成；

    if(profit <= 400000) {
        result += (size_t)((profit - 200000)*0.05);
        return result;
    }

    result += 10000;
    // 400000<profit≤600000元时，高于400000元的部分按3％提成
    if(profit <= 600000) {
        result += (size_t)((profit - 400000)*0.03);
        return result;
    }

    result += 6000;
    // 600000<profit≤1000000时，高于600000元的部分按1.5%提成；
    if(profit <= 1000000) {
        result += (size_t)((profit - 600000)*0.015);
        return result;
    }

    result += 6000;

    result += (size_t)((profit - 1000000)*0.01);

	return result;
}
