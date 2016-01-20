#include <stdlib.h>
#include "oj.h"


/*
功能：在字符串中找出连续最长的数字串，并把这个串的长度返回
函数原型：
    unsigned int Continumax(char** pOutputstr,  char* intputstr)
输入参数：
    char* intputstr  输入字符串
输出参数：
    char** pOutputstr: 连续最长的数字串，如果连续最长的数字串的长度为0，应该返回空字符串
    pOutputstr 指向的内存应该在函数内用malloc函数申请，由调用处负责释放
返回值：
  连续最长的数字串的长度
 */
unsigned int Continumax(char** pOutputstr,  char* intputstr) {

    if(intputstr == NULL) {
        *pOutputstr = (char *) malloc(sizeof(char));
        (*pOutputstr)[0] ='\0';
        return 0;
    }

    // 最大连续数字串的起始位置
    int maxIdx = 0;
    // 最大连续数字串的长度
    int maxLen = 0;

    for(int i = 0, j; intputstr[i] != '\0';) {
        j = i;

        // 找第一个数字
        while(intputstr[j] != '\0' && (intputstr[j] < '0' || intputstr[j] > '9')) {
            j++;
        }

        // 找连续数字后的第一个非数字
        i = j;
        while(intputstr[i] != '\0' && (intputstr[i] >= '0' && intputstr[i] <= '9')) {
            i++;
        }

        if(i - j > maxLen) {
            maxIdx = j;
            maxLen = i - j;
        }
    }

    // 字符串中有数字
    if(maxLen > 0) {
        (*pOutputstr) = (char *) malloc((maxLen + 1)*sizeof(char));

        for(int i = 0; i < maxLen; i++) {
            (*pOutputstr)[i] = intputstr[maxIdx];
            maxIdx++;
        }

        (*pOutputstr)[maxIdx] = '\0';
        return maxLen;
    }
    // 字符串中不含数字
    else {
        *pOutputstr = (char *) malloc(sizeof(char));
        (*pOutputstr)[0] ='\0';
        return 0;
    }
}

