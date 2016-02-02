#include <stdlib.h>
#include <iostream>


#include "OJ.h"

using namespace std;

/*

输入: nPapers表示试卷的数目(1≤Papers≤20)，nRemain表示剩余的时间(1≤nRemain≤10000)，paper[][2]是一个Papers*2的数组，

每一行的两个元素依次为做完这一份试卷所需的时间、做完这份试卷的价值。
如果剩余时间不够做完一份卷子，可根据剩余时间获得卷子的部分价值。

输出: *pMaxValue为获得的最大价值
返回:
0:异常
1:计算成功返回


*/

void quickSort(int paper[][2], int begPos, int endPos) {
    if(begPos < endPos) {
        int lo = begPos;
        int hi = endPos;
        int time = paper[begPos][0];
        int value = paper[begPos][1];
        double povitUnit = paper[begPos][1]*1.000/paper[begPos][0];

        while(lo < hi) {
            while(lo < hi && paper[hi][1]*1.000/paper[hi][0] <= povitUnit) {
                hi--;
            }
            paper[lo][0] =paper[hi][0];
            paper[lo][1] =paper[hi][1];

            while(lo < hi && paper[lo][1]*1.000/paper[lo][0] >= povitUnit) {
                lo++;
            }
            paper[hi][0] =paper[lo][0];
            paper[hi][1] =paper[lo][1];

        }

        paper[lo][0] = time;
        paper[lo][1] = value;
    }
}

int GetMaxValue(int nPapers, int nRemain, int paper[][2], double* pMaxValue) {

    if(nPapers < 1 || nRemain < 1 || paper == NULL || pMaxValue == NULL) {
        return 0;
    }

    quickSort(paper, 0, nPapers - 1);
/*
    for(int i = 0; i < nPapers; i++) {
        cout << (paper[i][1]*1.0/paper[i][0]) << " ";
    }

    cout << endl;
*/
    *pMaxValue = 0;

    int consum = 0;

    for(int i = 0; i < nPapers; i++) {
        if(consum + paper[i][0] <= nRemain) {
            *pMaxValue += paper[i][1];
            consum += paper[i][0];
        } else {
            *pMaxValue += paper[i][1]*1.000/paper[i][0]*(nRemain - consum);
            break;
        }
    }

    return 1;
}
