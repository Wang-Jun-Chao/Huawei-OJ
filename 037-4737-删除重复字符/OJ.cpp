#include <iostream>
#include<stdlib.h>
#include<set>
#include<vector>

#include "OJ.h"

using namespace std;

/*
Description
         给定一个字符串，将字符串中所有和前面重复多余的字符删除，其余字符保留，输出处理后的字符串。需要保证字符出现的先后顺序。
Prototype
         int GetResult(const char *input, char *output)
Input Param
         input     输入的字符串
Output Param
         output    输出的字符串
Return Value
         0         成功
         -1        失败及异常
*/
int GetResult(const char *input, char *output) {

    if(input == NULL || output == NULL) {
        return -1;
    }

    set<char> charSet;
    vector<char> charVector;

    for(int i = 0; input[i] != '\0'; i++) {
        if(charSet.find(input[i]) == charSet.end()) {
            charSet.insert(input[i]);
            charVector.push_back(input[i]);
        }
    }

    int idx = 0;
    for(vector<char>::iterator it  = charVector.begin(); it != charVector.end(); it++) {
        output[idx] = *(it);
        idx++;
    }

    output[idx] = '\0';


    return 0;
}
