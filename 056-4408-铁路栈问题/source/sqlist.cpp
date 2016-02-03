/******************************************************************************

  Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     :
  Version       :
  Author        :
  Created       : 2013/08/10
  Last Modified :
  Description   :
  Function List :

  History       :
  1.Date        : 2013/08/10
    Author      :
    Modification: Created file

******************************************************************************/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <vector>


using namespace std;
/*
详细描述：
int JudgeTrainSequence (int maxNum, char *pOutSeq);
输入参数：
	 	int maxNum：进站的火车最大编号
	 	char* pOutSeq：使用字符串表示火车出站序列
输出参数（指针指向的内存区域保证有效）：
	 	无。
返回值：
		Int: 根据输入的进站序列判断，如果输入的出战序列是可能的，返回1，否则返回0；

*/

int JudgeTrainSequence (int maxNum, char *pOutSeq) {

    if(maxNum < 1 || pOutSeq == NULL) {
        return 0;
    }

    vector<char> push;
    vector<char> pop;

    for(int i = 0; i < maxNum; i++) {
        push.push_back((char)('1' + i));
    }

    for(int i = 0; i < maxNum; i++) {
        pop.push_back(pOutSeq[i]);
    }

    vector<char> mstack;
    // 用于记录入栈数组元素的处理位置
    int pushIndex = 0;
    // 用于记录出栈数组元素的处理位置
    int popIndex = 0;

    // 如果还有出栈元素要处理
    while(popIndex < pop.size()) {
        // 入栈元素还未全部入栈的条件下，如果栈为空，或者栈顶的元素不与当前处理的相等，
        // 则一直进行栈操作，
        // 直到入栈元素全部入栈或者找到了一个与当出栈元素相等的元素
        while(pushIndex < push.size() &&
                (mstack.empty() || mstack[mstack.size()-1] != pop[popIndex])) {
            mstack.push_back(push[pushIndex]);
            pushIndex++;
        }

        // 如果在上一步的入栈过程中找到了与出栈的元素相等的元素
        if (mstack[mstack.size() - 1] == pop[popIndex]) {
            // 将元素出栈
            mstack.pop_back();
            // 处理下一个出栈元素
            popIndex++;
        }
        // 如果没有找到与出栈元素相等的元素，说明这个出栈顺序是不合法的
        // 就返回false
        else {
            return 0;
        }
    }

    return 1;
}


