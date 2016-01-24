#include "IPAddressValid.h"
#include <cstring>
#include <cstdio>

using namespace std;

bool isIPAddressValid(const char* pszIPAddr) {

    if(NULL == pszIPAddr) {
        return false;
    }

    // 字符串的长度
    int lenIPAddr=strlen(pszIPAddr);
    int startIndex;
    int endIndex;

    //去掉前后空格
    for(startIndex = 0; startIndex < lenIPAddr; startIndex++) {
        if(pszIPAddr[startIndex] != ' ') {
            break;
        }
    }

    for(endIndex = lenIPAddr - 1; endIndex >= 0; endIndex--) {
        if(pszIPAddr[endIndex]!=' ') {
            break;
        }
    }

    // 都是空格的情况
    if(endIndex <= startIndex) {
        return false;
    }

    char inputStr[200];
    // IP字符串的去掉首尾空格后的长度
    int lenInputStr = endIndex - startIndex + 1;

    // 将内容拷贝到inputStr中
    strncpy(inputStr, &pszIPAddr[startIndex], lenInputStr);

    // 设置结束位置
    inputStr[lenInputStr] = '\0';
    // 查找点的合法性
    // .号的个数
    int countDot = 0;

    for(int i = 0; i < lenInputStr; i++) {
        if(inputStr[i] == '.') {
            // 点号数加一
            countDot ++;

            // 第一个或者最后一个是点号
            if(i == 0 || i == lenInputStr - 1) {
                return false;
            }

            // 点号前一个必须是数字
            if(inputStr[i - 1] < '0' || inputStr[i-1] > '9') {
                return false;
            }

            // 点号后一个必须是数字
            if(inputStr[i + 1] < '0'|| inputStr[i + 1] > '9') {
                return false;
            }

        }
    }

    // 点号不足三个
    if(countDot != 3) {
        return false;
    }
    char *pCut;
    // 将字符串以.号进行分割
    // 得到第一个部分的首地址
    pCut = strtok(inputStr, ".");

    while(NULL != pCut) {
        int num;
        // 从一个字符串中读进与指定格式相符的数据。
        // 将字符串转成整形
        sscanf(pCut, "%d", &num);
        // 值不为0，并且有前导0
        if(num != 0 && pCut[0] == '0') {
            return false;
        }

        // 值超出255
        if(num > 255) {
            return false;
        }

        // 首次调用时，s指向要分解的字符串，之后再次调用要把s设成NULL。
        // 得到第二部分的首地址
        pCut = strtok(NULL,".");
    }

    return true;
}
/*
// 下面的例子不能通过全部测试用例，不知道未通过的例子是什么

bool ipToInt(const char * b, const char * e, int &rst) {

    //cout << *b << " " << *e << endl;

    // IP地址部分有前导0，或者第一个字符是其它非数字字符
    if(*b < '0' || *b > '9') { //
        return false;
    }


    int len = e - b + 1;
    int idx = 0;
    rst = 0;

    // cout << idx << "-" << len << endl;
    while( idx < len) {
        if(b[idx] >= '0' && b[idx] <= '9') {
            rst = rst * 10 + (b[idx] - '0');
        } else {
            return false;
        }

        idx++;
    }

    // 不为0但是有前导0
    if(rst > 0 && *b == '0') {
        return false;
    }

    if(rst >= 0 && rst < 256) {
        return true;
    }

    return false;


}

// 注意00.0.00.00是合法的
bool isIPAddressValid2(const char * pszIPAddr) {

    if(pszIPAddr == NULL || pszIPAddr[0] == '\0') {
        return false;
    }


    int b = 0;
    int e;

    // 找左边第一个非空白字符
    while(pszIPAddr[b] != '\0' && pszIPAddr[b] == ' ') {
        b++;
    }

    e = b + 1;
    while(pszIPAddr[e] != '\0') {
        e++;
    }
    e--;

    // 找右边第一个非空白字符
    while(b <=e && pszIPAddr[e] == ' ') {
        e--;
    }

    int idx = 0;
    int cnt = 0;
    while( idx <= e) {
        while(idx <= e && pszIPAddr[idx] != '.') {
            idx++;
        }

        // 注意当有两个连续的..会有b=idx的情况
        if(b == idx) {
            return false;
        }

        int v;
        bool result = ipToInt(pszIPAddr + b, pszIPAddr + idx - 1, v);
        cnt++;

        if(!result) {
            return false;
        }

        b = idx + 1;
        idx = idx + 1;
    }

    return cnt == 4;
    //return true;
}

*/
