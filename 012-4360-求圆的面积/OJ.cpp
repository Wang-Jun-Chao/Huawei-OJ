#include <stdlib.h>
#include <string.h>
#include "oj.h"


/*
功能:

输入:

输出:	arrValue:存储返回的符合范围之内的圆面积，内存在函数外已经申请
		nValue:返回数组的行数

返回:

*/

void OutputRotundityArea(float *arrValue,int &nValue) {
    float PI = 3.14;

    int idx = 0;
    float v;
    for(int i = 0; i < nValue; i++) {
        v = PI*arrValue[i]*arrValue[i];
        //if(v >= 40 && v <= 90) {
            arrValue[i] = v;
            idx++;
        //}
    }
}
