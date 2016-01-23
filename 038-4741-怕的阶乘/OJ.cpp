#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>

#include <iostream>

#include "oj.h"

using namespace std;

// 将字符串从个位到到低翻转
void numReverse(int v, vector<int> &vt) {
    do {
        vt.push_back(v%10);
        v /= 10;
    } while (v != 0);
}

void CalcNN(int n, char *pOut) {

    if(n < 0 || pOut == NULL) {
        return ;
    }

    if(n < 2) {
        pOut[0] = '1';
        pOut[1] = '\0';
    }

    vector<int> rst;
    vector<int> partialRst;
    partialRst.push_back(1);

    for(int v = 2; v <= n; v++) {
        vector<int> mul;
        numReverse(v, mul);

        rst.clear();
        rst.assign(partialRst.size() + mul.size() +1, 0);

        for(int i = 0; i < mul.size(); i++)  {
            int carry = 0;
            for(int j = 0; j < partialRst.size(); j++) {

                int sum = mul[i] * partialRst[j] + rst[i + j] + carry;

                // 下一位的进位
                carry = sum / 10;
                // 当前位的和
                rst[i + j] = sum % 10;
            }

            if(carry > 0) {
                partialRst.push_back(carry);
            }
        }

        partialRst.clear();
        for(vector<int>::iterator itr = rst.begin(); itr != rst.end(); itr++) {

            cout << *itr << " ";

            partialRst.push_back((*itr));
        }

        cout << endl;
    }

    int idx = 0;
    int findHigest = 0;
    for(vector<int>::reverse_iterator itr = rst.rbegin(); itr != rst.rend(); itr++) {

        if(*itr == 0 && findHigest == 0) {
            continue;
        }
        findHigest = 1;
        pOut[idx] = *itr + '0';
        idx++;
    }

    pOut[idx] = '\0';

    return;
}
