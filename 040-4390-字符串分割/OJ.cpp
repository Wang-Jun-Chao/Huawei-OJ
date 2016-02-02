#include <stdlib.h>
#include "oj.h"
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

char value[1000][9];
unsigned int len = 0;


/*****************************************************************
功能:存储输入的字符创

输入:字符串

输出:无

返回:0表示成功,其它返回-1
****************************************************************/
int  AddString(char *strValue) {

    if(strValue == NULL) {
        return -1;
    }

    int cnt = 0;
    // 求字符串的长度
    while(strValue[cnt] != '\0') {
        cnt++;
    }

    // 原数组中的位置
    int idx = 0;

    while(idx + 8 <= cnt) {
        for(int i = 0; i < 8; i++) {
            value[len][i] = strValue[idx + i];
        }

        value[len][8] = '\0';

        len++;
        idx += 8;
    }


    // 说明最后还有余下的
    if(idx < cnt || cnt == 0) {
        int num = (cnt - idx);
        for(int i = 0; i < num; i++) {
            value[len][i] = strValue[idx + i];
        }

        for(int i = num; i < 8; i++) {
            value[len][i] = '0';
        }

        value[len][8] = '\0';

        len++;
    }



    return 0;
}

/****************************************************************
功能:获取补位后的二维数组的长度

输入:无

输出:无

返回:二维数组长度
******************************************************************/
int  GetLength() {
    return len;
}

/*****************************************************************************
功能:将补位后的二维数组，与输入的二维数组做比较

输入:strInput:输入二维数组,iLen：输入的二维数组的长度

输出:无

返回:若相等,返回0;不相等,返回-1.其它:-1;
******************************************************************************/
int  ArrCmp(char strInput[][9],int iLen) {

    if(strInput == NULL || iLen < 1 || iLen != len) {
        return -1;
    }

    for(int i = 0; i < iLen; i++){
        for(int j = 0; j < 9; j++) {
            if(value[i][j] != strInput[i][j]) {
                return -1;
            }
        }
    }
    return 0;
}

void printMatrix() {
    for(int i = 0; i < len; i++) {
        cout << "|" << value[i] << "|" << endl;
    }
}

