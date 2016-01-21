#include <cstdlib>
#include <cstring>
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

    char *pTemp =new char[10];
    // void *memset(void *s, int ch, size_t n);
    // 函数解释：将s中前n个字节 （typedef unsigned int size_t ）用 ch 替换并返回 s 。
    // memset：作用是在一段内存块中填充某个给定的值，它是对较大的结构体或数组进行清零操作的一种最快方法
    memset(pTemp,'\0',10);
    char temp[10] = {""};

    // strcpy()是依据源串的\0作为结束判断的，不检查copy先的Buffer的Size，
    // 如果目标空间不够，就有BufferOverflow问题
    // strncpy的原型为：char * strncpy(char *dest, char *src, size_t n);
    // 其将字符串src中最多n个字符复制到字符数组dest中(它并不像strcpy一样遇到NULL才停止复制，
    // 而是等凑够n个字符才开始复制），返回指向dest的指针，所以，用户定义好size，就没有bufferoverfolow的风险
    // 目前，strncpy是字符串拷贝推荐的用法
    // 加_s版本则是从VS2005开始推出的安全版本，
    // 而加_s版本之所以安全，是因为他们在接口增加了一个参数numElems来表明dest中的字节数，
    // 防止目标指针dest中的空间不够而导致出现Bug，同时返回值改成返回错误代码，而不是为了一些所谓
    // 的方便而返回char*。这样接口的定义就比原来安全很多。但是，_s版本并不是标准库，所以，不推荐使用

    // 将字符串pTemp中的内容拷贝到temp中，长度为0个字符
    strncpy_s(pTemp, 10, temp, 10);

    // 如果输入串为空，就直接返回
    if (NULL == intputstr) {
        *pOutputstr  = pTemp;
        return 0;
    }

    // 求输入串的长度
    size_t strLen = strlen(intputstr);
    // 结果串的最大长度
    char* pMaxNum = new char[strLen + 1];
    // 连续数字串和长度
    size_t numLen = 0;
    // 连续数字串的最大长度
    size_t maxNumLen = 0;
    // 开始处理的位置
    size_t startNum = 0;

    // 对字符串进行处理
    for(size_t i = 0; i < strLen; ++i) {
        // 之前是非数字，现在是处理过程中第一个数字
        if (intputstr[i]>='0' && intputstr[i]<='9') {
            // 记录处理的起始位置
            startNum = i;
            // 用于记录本次数字串处理的长度
            numLen = 0;
            // 处理本次的数字串
            while(i < strLen && intputstr[i] >= '0' && intputstr[i] <= '9') {
                ++numLen;
                ++i;
            }

            // 如果找到的数字串比原来的长，就更新新的数字串
            if (numLen != 0 && maxNumLen <= numLen) {
                memset(pMaxNum, '\0', strLen + 1);
                strncpy_s(pMaxNum, strLen + 1, intputstr + startNum, numLen);
                maxNumLen = numLen;
            }
        }
    }

    if (maxNumLen == 0) {
        delete [] pMaxNum;
        pMaxNum = NULL;
        *pOutputstr = pTemp;
    } else {
        *pOutputstr = pMaxNum;
    }

    return (unsigned int)maxNumLen;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////
// 方法二有错误，原因还未知道
/*
unsigned int Continumax(char** pOutputstr,  char* intputstr) {

    if(pOutputstr == NULL || intputstr == NULL || intputstr[0] == '\0') {
        *pOutputstr = (char *) malloc(sizeof(char));
        (*pOutputstr)[0] ='\0';
        return 0;
    }

    // 字符串长度为0
    if(intputstr[0] == '\0') {
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
*/
