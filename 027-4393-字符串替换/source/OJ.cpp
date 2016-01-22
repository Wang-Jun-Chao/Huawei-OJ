#include <stdlib.h>
#include <string.h>
#include "oj.h"


/*
功能:

输入:

输出:

返回:成功0,其它-1

*/

int ProcessString( char * strInput,char chSrc,char chDes ,char * strOutput) {

    if(strInput == NULL || strOutput == NULL) {
        return -1;
    }

    char * p = strInput;
    char * q = strOutput;

    while(*p != '\0') {
        if(*p == chSrc) {
            *q = chDes;
        } else {
            *q = *p;
        }
        p++;
        q++;
    }

    *q = *p;
    return 0;
}
