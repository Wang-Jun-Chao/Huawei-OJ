#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "oj.h"

// 功能：排列一个m行n列 大小的数组
// 输入： int * pArray 指向数组第一个元素的指针,m为行数， n为列数 ，请按第i列排列
// 输出：按第i列排序完成后的数组放到入参指定的地址中	(i的取值范围 1 - n)
// 返回：

// 交换第i行和第j行的数据
void ExchangeRow(int * arr, unsigned int iRow, unsigned int jRow, unsigned int colNum) {

    int t;
    int iEnd = (iRow + 1)*colNum;

    for(int i = iRow*colNum, j = jRow*colNum; i < iEnd; i++, j++) {
        t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}

int NeedChange(int * arr, int iRow, int iCol, int jRow, int jCol, int colNum) {
    int i= iRow*colNum  + iCol;
    int iEnd = (iRow + 1)*colNum;
    int j = jRow*colNum + jCol;

    while(i < iEnd) {
        if(arr[i] != arr[j]) {
            return arr[i] - arr[j];
        } else {
            i++;
            j++;
        }
    }

    return 0;
}

void RangeArray(int * pArray,unsigned int  m, unsigned int  n,unsigned int  i) {
    if(pArray == NULL || m < 1 || n < 1 || i < 1 || i > n) {
        return;
    }

    i--;
    for(int row = 0; row < m; row++) {
        for(int nxt = row + 1; nxt < m; nxt++) {
            int rst = NeedChange(pArray, row, i, nxt, i, n);
            // 说明要交换
            if(rst > 0) {
                ExchangeRow(pArray, row, nxt, n);
            }
        }
    }
}



