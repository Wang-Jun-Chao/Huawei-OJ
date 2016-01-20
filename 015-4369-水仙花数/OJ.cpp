#include <stdlib.h>
#include "oj.h"

unsigned int power(unsigned int x, unsigned int y) {
    unsigned int rst = 1;
    for(int i = 0; i < y; i++) {
        rst *= x;
    }

    return rst;
}

// 功能：判断输入 nValue 是否为水仙花数
// 输入： nValue为正整数
// 输出：无
// 返回：如果输入为水仙花数，返回1，否则返回0
unsigned int IsDaffodilNum(unsigned int  nValue) {

    unsigned int cnt = 0;
    unsigned int v = nValue;
    unsigned int t = 0;

    // 求nValue是多少位数
    do {
        cnt++;
        v /= 10;
    } while(v != 0);

    v = nValue;

    do {
        unsigned int n = v % 10;
        t += power(n, cnt);
        v /= 10;
    } while(v != 0);

    if(t == nValue) {
        return 1;
    }


    return 0;
}
