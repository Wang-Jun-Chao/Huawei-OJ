#include <stdlib.h>
#include "oj.h"


unsigned int  GetLastThreeNumOfResult (unsigned int  m, unsigned int  n) {

    unsigned int times = n;
    m %= 1000;
    n %= 1000;
    unsigned int rst = 1;
    for(int i = 0; i < times; i++) {
        rst = (rst * m)%1000;
    }
    return rst;
}
