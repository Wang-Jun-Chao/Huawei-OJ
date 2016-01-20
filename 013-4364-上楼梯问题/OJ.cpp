#include <stdlib.h>
#include "oj.h"
// 功能：计算满足条件的楼梯的长度
// 输入： 无
// 输出：无
// 返回： 无

unsigned int  GetStairNum () {

    int step = 7;
    while(true) {
        if((step % 2) == 1 && (step % 3) == 2 && (step % 5) == 4 && (step % 6) == 5) {
            break;
        }

        step += 7;
    }
    return step;
}
