#include <cstdlib>
#include "OJ.h"

/*
功能:对输入的整型数组，输出数组元素中的最大值、最大值的个数、最小值和最小值的个数

输入:int * pInputInteger：整型数组指针
	 int * InputNum：数组元素个数

输出:int * pMaxValue：数组中最大值
  	 int * pMaxNum：数组中最大值的个数
	 int * pMinValue：数组中最小值
     int * pMinNum：数组中最小值的个数

返回:void
*/

void OutputMaxAndMin(int * pInputInteger, int InputNum, int * pMaxValue, int * pMaxNum, int * pMinValue, int * pMinNum) {

    if(InputNum < 1 || pInputInteger == NULL || pMaxValue == NULL
            || pMinValue == NULL || pMinNum == NULL) {
        return ;
    }

    *pMaxValue = pInputInteger[0];
    *pMaxNum = 1;

    *pMinValue = pInputInteger[0];
    *pMinNum = 1;

    for(int i = 1; i < InputNum; i++) {

        // cout << pInputInteger[i] << " " << *pMaxValue << " " << *pMinValue << endl;

        if(pInputInteger[i] < *pMinValue) {

            *pMinValue = pInputInteger[i];
            *pMinNum = 1;
        } else if(pInputInteger[i] == *pMinValue) {
            (*pMinNum)++;
        }

        if(pInputInteger[i] > *pMaxValue) {
            *pMaxValue = pInputInteger[i];
            *pMaxNum = 1;
        } else if(pInputInteger[i] == *pMaxValue) {
            (*pMaxNum)++;
        }
    }
    return;
}

