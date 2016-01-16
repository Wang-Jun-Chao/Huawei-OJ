#include <math.h>
#include "OJ.h"


bool IsSameConstructNum(int n) {
    if (n < 1) {
        return false;
    }

    long m = n*n;

    while(n != 0) {
        if(n%10 == m%10) {
            n /= 10;
            m /= 10;
        } else {
            return false;
        }
    }

    return true;
}
/*
功能:找出1至n之间同构数的个数
输入：
    int n：查找1至n之间的全部同构数
返回：
    int：1至n之间同构数的个数
*/
int SearchSameConstructNum(int n) {

    int result = 0;

    for(int i = 1; i <= n; i++) {
        if(IsSameConstructNum(i)) {
            result++;
        }
    }


    return result;
}
