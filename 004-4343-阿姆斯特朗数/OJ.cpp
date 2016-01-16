#include "OJ.h"

bool IsArmstrongNumber(int n) {
    if(n < 2) {
        return false;
    }
    int sum = 0 ;
    int t = 0;
    int v = n;
    while(v != 0) {
        t = v%10;
        v /= 10;
        sum += t*t*t;
    }
    return sum == n;
}

/*
功能: 求n(n ≤ 65536)以内的所有阿姆斯特朗数
原型：
    int CalcArmstrongNumber(int n);

输入参数：
    int n: n ≤ 65536

返回值：
    n以内的阿姆斯特朗数的数量。
*/

int CalcArmstrongNumber(int n)
{
    /*在这里实现功能*/
    int result = 0;

    for(int i = 2; i <=n ;i++) {
        if(IsArmstrongNumber(i)) {
            result++;
        }

    }

    return result;
}


