#include <stdlib.h>
#include "OJ.h"

/*
功能: 找出字符串中第一个出现次数最多的字符

输入: char* pInputString：字符串

输出: char* pChar：出现次数最多的字符

返回: false 异常失败
	  true  输出成功
*/
bool FindChar(char* pInputString, char* pChar) {

    if(pInputString == NULL || pInputString[0] == '\0') {
        return false;
    }

    int arr[256][2] = {0};

    for(int i = 0; i < 256; i++) {
        arr[i][0] = arr[i][1] = 0;
    }

    for(int i = 0; pInputString[i] != '\0'; i++) {
        // 记录字符出现的次数
        arr[pInputString[i]][0]++;
        if(arr[pInputString[i]][1] == 0) {
            // 记录字符第一次出现的位置
            arr[pInputString[i]][1] = i;
        }
    }

    int cnt = 0;
    int idx = 0;

    for(int i = 0; i < 256; i++) {
        // 记录字符出现最多的次数和第一次出现的位置
        if(cnt < arr[i][0]) {
            idx = i;
            cnt = arr[i][0];
        } else if(cnt == arr[i][0]) {
            if(idx > i) {
                idx = i;
            }
        }
    }

    //cout << pInputString << endl;
    //cout << idx << endl;
    //cout << (char)(idx) << endl;



    *pChar = (char)(idx);


    return true;
}

