/******************************************************************************

  Copyright (C), 2001-2013, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     :
  Version       :
  Author        :
  Created       : 2013/03/12
  Last Modified :
  Description   :
  Function List :

  History       :
  1.Date        : 2013/03/12
    Author      :
    Modification: Created file

******************************************************************************/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <list>
#include <iostream>

#include "OJ.h"

using namespace std;

// 计算逆波兰式的值
void calInversePoland(list<float> &intList, bool &rst) {

/*
     for (list<float>::iterator itr = intList.begin(); itr != intList.end(); itr++) {
         int i = *itr;
        if(i >= 0 && i <= 10) {
            cout << i << " ";
         } else {
            cout << (char)i << " ";
         }
     }

     cout << endl;
*/
    list<float> mstack;;

    for (list<float>::iterator itr = intList.begin(); itr != intList.end(); itr++) {

        // 如果是数字
        if (*itr >= 0 && *itr <= 10) {
            mstack.push_back(*itr);
        } else {
            float a = mstack.back();
            mstack.pop_back();
            float b = mstack.back();
            mstack.pop_back();
            float c = 0;
            switch ((char)(*itr)) {
            case '+':
                c = a + b;
                break;
            case '-':
                c = a - b;
                break;
            case '*':
                c = a * b;
                break;
            case '/':
                // 除数不能为0
                if (b == 0) {
                    return;
                }
                c = a / b;
                break;
            }

            mstack.push_back(c);
        }

    }

    float v = mstack.back();
    //cout << v << endl;
    rst = (v == 24);
}

void to24(float *arr, bool *used, int len, int numCnt, int optCnt,
                         list<float> &intList, bool &rst) {


    // 如果已经找到答案就不进行操作了
    if (rst) {
        return;
    }
    // 已经完成了逆波兰式的构造
    if (numCnt > optCnt && numCnt + optCnt == 7) {
        calInversePoland(intList, rst);
    }
    // 还要构造逆波兰式
    else if (numCnt > optCnt) {

        for (int i = 0; i < len; i++) {
            // 如果arr[i]还没有被使用过，或者arr[i]是运算符
            if (!used[i] || arr[i] < 0 || arr[i] > 10) {
                // 如果是数字
                if (arr[i] >= 0 && arr[i] <= 10) {
                    intList.push_back(arr[i]);
                    numCnt++;
                    used[i] = true;


                    to24(arr, used, len, numCnt, optCnt, intList, rst);

                    // 找到了一个答案就返回
                    if (rst) {
                        return;
                    }

                    intList.pop_back();
                    numCnt--;
                    used[i] = false;

                }
                // 如果是操作符，则放入arr[i]之前，操作数必须比操作符多两个
                else if (numCnt + 1 > optCnt) {
                    intList.push_back(arr[i]);
                    optCnt++;
                    used[i] = true;


                    to24(arr, used,len, numCnt, optCnt, intList, rst);

                    // 找到了一个答案就返回
                    if (rst) {
                        return;
                    }

                    intList.pop_back();
                    optCnt--;
                    used[i] = false;
                }
            }
        }
    }
}

// a, b, c, d都在[1, 10]内
bool Game24Points(int a, int b, int c, int d){
    float arr[8] = {a, b, c, d, '+', '-', '*', '/'};
    bool used[8] = {false};
    list<float> intList;

    bool rst = false;

    // 构造组合的逆波兰表达式
    for (int i = 0; i < 4; i++) {
        used[i] = true;



        intList.push_back(arr[i]);

        to24(arr, used, 8, 1, 0, intList, rst);

        if (rst) {
            return true;
        }

        // 现场还原
        intList.pop_back();
        used[i] = false;
    }


    return false;
}

