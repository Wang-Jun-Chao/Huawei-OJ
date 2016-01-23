
#include "OJ.h"
#include <string.h>
#include <vector>
#include <math.h>
#include <iostream>



using namespace std;

/*
功能:计算字符串的最小周期。
原型：
    int GetMinPeriod(char *string);

输入参数：
    char * string：字符串。

返回值：
    int 字符串最小周期。

*/

// 找n除了自己以外的所有约数
int getDivisor(vector<int> &iv, int n) {
    if(&iv == NULL) {
        return -1;
    }

    int s = n/2;
    iv.push_back(1);
    for(int i = 2; i <= s; i++) {
        if(n % i == 0) {
            iv.push_back(i);
        }
    }

    return 0;
}

bool isCycle(char * str, int cycle) {

    char * p;
    char * q;
    int step = cycle;
    do {
        p = str;
        q = str + step;

        while(q < str + step + cycle ) {

            //cout << *p << " " << *q << endl;

            if(*p == *q) {
                p++;
                q++;
            } else {
                return false;
            }
        }
        step += cycle;
    } while (*q != '\0');

    return true;
}

int GetMinPeriod(char *inputstring) {

    if(inputstring == NULL || *inputstring == '\0') {
        return 0;
    }

    // 求字符串的长度
    char * p = inputstring;
    int len = 0;
    while(*p != '\0') {
        len++;
        p++;
    }

    vector<int> iv;
    getDivisor(iv, len);

    for(vector<int>::iterator itr = iv.begin(); itr != iv.end(); itr++) {
        if(isCycle(inputstring, *itr)) {
            return *itr;
        }
    }

    iv.clear();

    // 找n除了自己以外的所有约数都不是周期串
    return len;
}
