/******************************************************************************

  Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     :
  Version       :
  Author        :
  Created       : 2009/10/10
  Last Modified :
  Description   :
  Function List :

  History       :
  1.Date        : 2009/10/10
    Author      :
    Modification: Created file

******************************************************************************/
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string trim(string s);
string format(string s);
string appendZero(string s, int n);
void strToArr(string s, vector<int> &v);
bool mcompares(vector<int> &m, vector<int> &s);
void minusOper(vector<int> &m, vector<int> &s, vector<int> &rst);
void addOper(vector<int> &m, vector<int> &s, vector<int> &rst);
void printVector(vector<int> &v);
/*****************************************************************************
Description  : 两个任意长度的正数相减
Prototype    : int Decrease(const char *pMinuend, const char *pSubtrahend, char **ppResult)
Input Param  : const char *pMinuend     被减数，以\0表示字符串结束
               const char *pSubtrahend  减数，以\0表示字符串结束
Output       : char **ppResult          减法结果，必须以\0表示字符串结束
Return Value : 成功返回0   失败返回-1
*****************************************************************************/
int Decrease(const char *pMinuend, const char *pSubtrahend, char **ppResult) {

    if(pMinuend == NULL || pMinuend[0] == '\0' || pSubtrahend == NULL
            || pSubtrahend[0] == '\0' || ppResult == NULL) {
        return -1;
    }

    string mstr(pMinuend);
    string sstr(pSubtrahend);



    // 去掉两端空格
    mstr = trim(mstr);
    sstr = trim(sstr);

    // 记录是正数还是负数
    bool mPositive = true;
    bool sPositive = true;

    // 去掉符号
    if(mstr[0] == '+') {
        mstr = mstr.substr(1, mstr.length() - 1);
    } else if(mstr[0] == '-') {
        mPositive = false;
        mstr = mstr.substr(1, mstr.length() - 1);
    }

    if(sstr[0] == '+') {
        sstr = sstr.substr(1, sstr.length() - 1);
    } else if(sstr[0] == '-') {
        sPositive = false;
        sstr = sstr.substr(1, sstr.length() - 1);
    }



    // 归整数字字符串
    mstr = format(mstr);
    sstr = format(sstr);



    // 记录有多少位小数
    int mDecimal = mstr.find('.');
    int sDecimal = sstr.find('.');


    if (mDecimal == -1) {
        mDecimal = 0;
    } else {
        mDecimal = mstr.length() - (mDecimal + 1);
    }

    if (sDecimal == -1) {
        sDecimal = 0;
    } else {
        sDecimal = sstr.length() - (sDecimal + 1);
    }

    // 被减数的小数位多
    if (mDecimal > sDecimal) {
        // 在减数后面添加零
        sstr = appendZero(sstr, mDecimal - sDecimal);
    }
    // 减数的位数不小于被减数
    else {
        // 在被减数后面添加0
        mstr = appendZero(mstr, sDecimal - mDecimal);
    }

    // 记录结果的小数位数
    int decimal = mDecimal > sDecimal ? mDecimal : sDecimal;
    vector<int> m;
    vector<int> s;
    strToArr(mstr, m);
    strToArr(sstr, s);

    /////////////////////////////////////////////////////////
   // printVector(m);
   // printVector(s);
    /////////////////////////////////////////////////////////


    // 被减数是否大于等于s
    bool isMgeS = mcompares(m, s);

    //cout << "m >= s ? " << isMgeS << endl;

    vector<int> rst;
    bool isResultPositive = true;

    // 判断结果是正还是负数
    // 两个数都是正数，并且第一个数不小于第二个数
    if (mPositive && sPositive && isMgeS) {
        isResultPositive = true;
        minusOper(m, s, rst);
    }
    // 两个数都是正数，并且第一个数小于第二个数
    else if (mPositive && sPositive && !isMgeS) {
        // cout << "====" << endl;
        isResultPositive = false;
        minusOper(s, m, rst);
    }
    // 第一个数是正数，第二个数是负数
    else if (mPositive && !sPositive) {
        isResultPositive = true;
        addOper(m, s, rst);
    }
    // 第一个数是负数，第二个数是正数
    else if (!mPositive && sPositive) {
        isResultPositive = false;
        addOper(m, s, rst);
    }
    // 两个数都是非正数，并且第一个数大于第二个数
    else if (!mPositive && !sPositive && isMgeS) {
        isResultPositive = false;
        minusOper(m, s, rst);
    }
    // 两个数都是非正数，并且第一个数小于第二个数
    else if (!mPositive && !sPositive && !isMgeS) {
        isResultPositive = true;
        minusOper(s, m, rst);
    }

    /////////////////////////////////////////////////////////
    //printVector(rst);
    /////////////////////////////////////////////////////////

    vector<char> result;

    // 添加整数部分
    for (int i = rst.size() - 1; i >= decimal ; i--) {
        result.push_back((char)(rst[i] + '0'));
    }



    // 有小数
    if (decimal > 0) {
        result.push_back('.');
        // 添加小数部分
        for (int i = decimal - 1; i >= 0 ; i--) {
            result.push_back((char)(rst[i] + '0'));
        }
    }

    // 有小数
    if (decimal > 0) {
        int idx = result.size() - 1;

        // 去掉秘尾部0
        while (result[idx] == '0') {
            idx--;
        }

        // 最后一个小数点，去掉小数点
        if (result[idx] == '.') {
            idx--;
        }

        result.resize(idx + 1);
    }

    // 去掉多余前导零
    int idx = 0;
    while (result[idx] == '0') {
        idx++;
    }

    if (result[idx] == '.') {
        idx--;
    }

    string resultString("");

    for(int i = idx; i < result.size(); i++) {
        resultString.append(1, result[i]);
    }

    if (!isResultPositive) {
        resultString = "-" + resultString;
    }


    *ppResult = (char *)malloc(sizeof(char)*(resultString.length() + 1));
    for(int i = 0; i < resultString.length(); i++) {
        (*ppResult)[i] = resultString[i];
    }

    (*ppResult)[resultString.length()] = '\0';

    //cout << resultString << endl;

    return 0;
}

// 去掉s两端的空格，保证s必须含有空格以外的字符
string trim(string s) {

    int beg = 0;
    while(beg < s.length() && s[beg] == ' ') {
        beg++;
    }

    int end = s.length() - 1;
    while(end >= 0 && s[end] == ' ') {
        end--;
    }

    return s.substr(beg, end - beg + 1);
}

// 将数字符串的进行归整（整理成正规的数字字符串）00.1-->0.1 .1->0.1 0.-->0.0
string format(string s) {

    // 去掉前导0
    int pos = 0;
    while (pos < s.length() && s[pos] == '0') {
        pos++;
    }
    s = s.substr(pos, s.length() - pos);

    // 如果s为空就返回零
    if (s.empty()) {
        s = "0";
    } else {
        // 如果最后一个字符是点号就补后面一个零
        if (s[s.length() - 1] == '.') {
            s += "0";
        }

        // 如果第一个是点号，就在最前页面添加一个0
        if (s.empty()) {
            s = "0" + s;
        }
    }

    return s;
}


string appendZero(string s, int n) {
    for (int i = 0; i < n; i++) {
        s += "0";
    }

    return s;
}

// 将数字字符串转成数字链表，从左到右为从低位到高位，去掉小数点
void strToArr(string s, vector<int> &v) {
    for (int i = s.length() - 1; i >= 0; i--) {
        char c = s[i];
        if (c >= '0' && c <= '9') {
            v.push_back(c - '0');
        }
    }

}

// m是否大于等于s，m和s有同样多的小数数位，并且m，s已经被归整过了
bool mcompares(vector<int> &m, vector<int> &s) {
    if (m.size() > s.size()) {
        return true;
    } else if (m.size() < s.size()) {
        return false;
    } else {
        for (int i = m.size() - 1; i >= 0; i--) {
            if (m[i] > s[i]) {
                return true;
            } else if (m[i] < s[i]) {
                return false;
            }
        }
    }

    return true;
}

// m-s，前提是m大于等于s
void minusOper(vector<int> &m, vector<int> &s, vector<int> &rst) {

    int max = m.size();
    int min = s.size();


    // 是否被借位
    int borrow = 0;
    int i = 0;
    while (i < min) {
        int mBit = m[i] - borrow;
        int sBit = s[i];

        if (mBit >= sBit) {
            rst.push_back(mBit - sBit);
            borrow = 0;
        } else {
            rst.push_back(10 + mBit - sBit);
            borrow = 1;
        }

        i++;
    }

    while (i < max) {
        int mBit = m[i] - borrow;
        if (mBit >= 0) {
            rst.push_back(mBit);
            borrow = 0;
        } else {
            rst.push_back(10 + mBit);
            borrow = 1;
        }
        i++;
    }

    //printVector(m);
    //printVector(s);
    //printVector(rst);
}
// 求m+s，m，s有相同位数的小数，并且m，s已经被归整过了
void addOper(vector<int> &m, vector<int> &s, vector<int> &rst) {
    if (m.size() < s.size()) {
        addOper(s, m, rst);
        return;
    }

    int max = m.size();
    int min = s.size();
    int i = 0;
    int carry = 0;


    while (i < min) {
        int sum = s[i] + m[i] + carry;
        carry = sum / 10;
        rst.push_back(sum % 10);
        i++;
    }

    while (i < max) {
        int sum = m[i] + carry;
        carry = sum / 10;
        rst.push_back(sum % 10);
        i++;
    }

    if (carry > 0) {
        rst.push_back(carry);
    }
}

void printVector(vector<int> &v) {
    for(vector<int>::iterator itr = v.begin(); itr != v.end(); itr++) {
        cout << (*itr) << " ";
    }

    cout << endl;
}












