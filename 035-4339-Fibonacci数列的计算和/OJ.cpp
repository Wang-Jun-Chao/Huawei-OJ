/******************************************************************************

  Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     :
  Version       :
  Author        :
  Created       : 2012/07/18
  Last Modified :
  Description   :
  Function List :

  History       :
  1.Date        : 2012/07/18
    Author      :
    Modification: Created file

******************************************************************************/


/************************************************************************/
/*  GetExtFibonacci                                                         */
/*  输入扩展Fibonacci数列的前2个数字first和second，要得到的数字的序列号num  */
/*  输入：扩展Fibonacci数列对应的序号的数字                                 */
/************************************************************************/
int GetExtFibonacci(int first , int second, int num) {
    if(num < 1) {
        return 0;
    }

    if(num == 1) {
        return first;
    } else if (num == 2) {
        return second;
    }

    int rst = 0;

    for(int i = 3; i <= num; i++) {
        rst = first + second;
        first = second;
        second = rst;
    }


    return rst;
}

/************************************************************************/
/*  CalcTotalValueOfExtFibonacci                                        */
/*  输入扩展Fibonacci数列的前2个数字first和second，和数字的序列号num    */
/*  输出：扩展Fibonacci数列对应的序号的数列之前（包括这个数列本身）的所有的数列之和         */
/************************************************************************/
int CalcTotalValueOfExtFibonacci(int first , int second, int num) {

    if(num <1) {
        return 0;
    }

    if(num == 1) {
        return first;
    }

    if(num == 2) {
        return first + second;
    }

    int rst = GetExtFibonacci(first, second, num) + CalcTotalValueOfExtFibonacci(first, second, num - 1);


    return rst;
}

