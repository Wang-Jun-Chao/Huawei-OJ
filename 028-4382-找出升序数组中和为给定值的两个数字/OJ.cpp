#include <stdio.h>
#include "OJ.h"

/*
功能: 输入一个已经按升序排序过的数组和一个数字，在数组中查找两个数，使得它们的和正好是输入的那个数字。如果有多对数字的和等于输入的数字，输出任意一对即可。

输入: int aData[]           // 升序数组
      unsigned int uiLength // 数组元素个数
      int sum,              // 给定两个数组的和

输出: int *pNum1            // 第一个数字，对应数组索引小的
      int *pNum2            // 第二个数字，对应数组索引大的

返回: 找到返回true，异常返回false
*/
bool FindTwoNumbersWithSum(int aData[], unsigned int uiLength, int sum, int *pNum1, int *pNum2) {
    if(aData == NULL) {
        return false;
    }

    for(int i = 0, j = uiLength -1; i < j; ) {
        if(aData[i] + aData[j] == sum) {
            *pNum1 = aData[i];
            *pNum2 = aData[j];
            return true;
        } else if(aData[i] + aData[j] < sum) {
            i++;
        } else {
            j--;
        }
    }


    return false;
}
