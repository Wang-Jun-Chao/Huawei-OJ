#include <stdlib.h>
#include <string.h>
#include <list>

#include "oj.h"

using namespace std;

int intConvert(list<int> &intList, int a) {


    if(NULL == &intList) {
        return -1;
    }

    if(a < 0) {
        a *= -1;
    }
    list<int> t;
    do {
        t.push_front(a%10);
        a /= 10;

    } while(a != 0);

    intList.insert(intList.end(), t.begin(), t.end());
    t.clear();

    return 0;
}

int intConvert(list<int> &intList, int a, int b) {

    if(&intList == NULL) {
        return -1;
    }

    intList.clear();
    intConvert(intList, a);
    intConvert(intList, b);

    return 0;
}


int compare(list<int> &a, list<int> &b) {

    if(NULL == &a) {
        return -1;
    }

    if(NULL == &b) {
        return 1;
    }

    for(list<int>::iterator aItr = a.begin(), bItr = b.begin();
            aItr != a.end() && bItr != b.end(); aItr++, bItr++) {
        if((*aItr) != (*bItr)) {
            return (*aItr) - (*bItr);
        }
    }


    return a.size() - b.size();

}

int mysort(int a[], int len) {

    if(a == NULL || len < 1) {
        return -1;
    }

    list<int> ar;
    list<int> br;

    // 下面使用插入排序，可以使用快排更好
    for(int i = 0; i < len; i++) {
        int idx = i;
        for(int j = i + 1; j < len; j++) {
            intConvert(ar, a[idx], a[j]);
            intConvert(br, a[j], a[idx]);

            if(compare(ar, br) > 0) {
                idx = j;
            }


        }

        int t = a[i];
        a[i] = a[idx];
        a[idx] = t;
    }

    return 0;
}

// 功能：将输入的数组排成最小的数
// 输入： int a[]:整型数组
//        int nCount:数组长度
//        char * strRst 返回值
// 输出：
// 返回：成功返回0  异常返回-1
int  smallestDigit(int a[],int nCount,char * strRst) {
    if(NULL == a || NULL == strRst) {
        return -1;
    }

    mysort(a, nCount);

    list<int> mList;

    for(int i = 0; i < nCount; i++) {
        intConvert(mList, a[i]);
    }

    int idx = 0;
    for(list<int>::iterator itr = mList.begin(); itr != mList.end(); itr++) {
        strRst[idx] = (*itr) + '0';
        idx++;
    }

    mList.clear();

    strRst[idx] = '\0';

    return 1;
}

