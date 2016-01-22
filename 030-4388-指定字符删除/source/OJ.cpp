#include <stdlib.h>
#include "oj.h"
/*
功能: 字符串中删除指定字符

输入: in, c

输出: out

返回: 0

*/

int removechars(char *in, char c, char *out) {

    if(in == NULL || out == NULL) {
        return 0;
    }

    char * p = in;
    char * q = out;

    while(*p != '\0') {
        if(*p != c) {
            *q = *p;
            q++;
        }
        p++;
    }

    *q = '\0';

    return 0;
}
