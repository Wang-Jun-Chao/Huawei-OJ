/******************************************************************************

Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

******************************************************************************
File Name     :
Version       :
Author        :
Created       :
Last Modified :
Description   :
Function List :

History       :
1.Date        :
Author      :
Modification: Created file

******************************************************************************/
#include <algorithm>
#include <vector>
using namespace std;

//给出一个非负整数，找到这个非负整数中包含的最大递减数。一个数字的递减数是指相邻的数位从大到小排列的数字。
//如： 95345323，递减数有：953,95,53,53,532,32, 那么最大的递减数为953。
//如果输入的数字为负数，返回-1。
int getMaxDegressiveNum (int num) {
    if(num < 0 ){
        return -1;
    }

    int cnt = 0;
    int t = num;

    // 求数的每一位
    vector<int> intVector;

    do {
        intVector.push_back(t%10);
        t /= 10;

    } while(t != 0);

    // 翻转vector
    reverse(intVector.begin(), intVector.end());

    int temp;
    int i;
    int max;

    max = temp = intVector[0];
    for(i=1; i< intVector.size(); i++)
    {
        if (intVector[i] < intVector[i-1]) {
            temp = temp * 10 + (intVector[i]);
        }

        else {
            temp = intVector[i];
        }

        if (temp > max) {
            max = temp;
        }

    }
    return max;

}

///////////////////////////////////////////////////////// 下面方法示能通过所有测试用例
/*
int getNum(vector<int> &intVector, int beg, int end) {
    int rst = 0;
    while(beg < end) {
        rst = rst * 10 + intVector[beg];
        beg++;
    }

    return rst;
}


int getMaxDegressiveNum2 (int num) {

    if(num < 0 ){
        return -1;
    }

    int cnt = 0;
    int t = num;

    // 求数的每一位
    vector<int> intVector;

    do {
        intVector.push_back(t%10);
        t /= 10;

    } while(t != 0);

    // 翻转vector
    reverse(intVector.begin(), intVector.end());

    int rst = -1;
    int prev = 0;
    int next = 1;
    while(next < intVector.size()) {
        while(next < intVector.size() && intVector[next - 1] > intVector[next]) {
            next++;
        }

        int v = getNum(intVector, prev, next);
        if(rst < v) {
            rst = v;
        }
        prev = next;
        next++;

    }

    if(next == 1) {
        rst = num;
    }


    return rst;
}

*/
