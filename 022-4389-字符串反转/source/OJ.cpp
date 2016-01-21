#include <stdlib.h>
#include <string.h>
#include "oj.h"


/*
功能:

输入:

输出:

返回:success :0,fail:-1

*/

int ProcessString(char * strInput,char * strOutput) {

    if(strInput == NULL || strInput[0] == '\0') {
        return -1;
    }

    int len = 0;

    while(strInput[len] != '\0') {
        len++;
    }

    for(int i =0, j = len - 1; i < len; i++, j--) {
        strOutput[i] = strInput[j];
    }

    strOutput[len] = '\0';

    return 0;
}
