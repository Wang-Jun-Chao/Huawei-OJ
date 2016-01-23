#include <vector>
#include <string>

#include "oj.h"

using namespace std;

// 将字符串从个位到到低翻转
void numReverse(const std::string s, vector<int> &vt) {

    int len = s.size();
    for(int i = len - 1; i >= 0; i--) {
        vt.push_back(s[i] - '0');
    }
}
/*****************************************************************************
 Prototype    : multiply
 Description  : 两个任意长度的长整数相乘, 输出结果
 Input Param  :
                const std::string strMultiplierA  乘数A
                const std::string strMultiplierB  乘数B
 Output       :
                std::string strRst            乘法结果
 Return Value :
                int                       0  正确
                                         -1  异常
*****************************************************************************/
int multiply (const std::string strMultiplierA,const std::string strMultiplierB, std::string &strRst) {

    if(&strMultiplierA == NULL || strMultiplierA.empty()
       || &strMultiplierB == NULL || strMultiplierB.empty() || &strRst == NULL) {
        return -1;
    }
/*
    int aNegative = 0;
    int bNegative = 0;
    if(strMultiplierA[0] == '-' ) {
        strMultiplierA = strMultiplierA.substr(1, strMultiplierA.size() - 1);

    }
*/

    vector<int> a;
    vector<int> b;
    numReverse(strMultiplierA, a);

    numReverse(strMultiplierB, b);

    vector<int> rst;
    rst.assign(a.size() + b.size() +  1, 0);

    for(int i = 0; i < a.size(); i++)  {
        int carry = 0;
        for(int j = 0; j < b.size(); j++) {

            int sum = a[i] * b[j] + rst[i + j] + carry;

            // 下一位的进位
            carry = sum / 10;
            // 当前位的和
            rst[i + j] = sum % 10;
        }

        int idx = b.size() + i;
        while(carry > 0) {
            carry = carry + rst[idx];
            rst[idx] = carry % 10;
            carry /= 10;
            idx++;
        }
    }

    int idx = 0;
    int findHigest = 0;
    for(vector<int>::reverse_iterator itr = rst.rbegin(); itr != rst.rend(); itr++) {

        if(*itr == 0 && findHigest == 0) {
            continue;
        }
        findHigest = 1;
        strRst  += *itr + '0';
        idx++;
    }

    // 结束全部都是0
    if(findHigest == 0) {
        strRst += '0';
    }

    return 0;
}
