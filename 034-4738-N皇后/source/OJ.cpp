#include <stdlib.h>
#include <memory.h>
#include <math.h>

#include "OJ.h"

// 检查第K个元素是否可以放
bool check(int *board, int k) {
    for (int i = 0; i < k; i++) {
        if (abs(k - i) == abs(board[k] - board[i]) || board[i] == board[k]) {
            return false;
        }
    }

    return true;
}
/*
功能: 求解放置8皇后方案的个数。
输入：
    无
返回：
    int：放置8皇后方案的个数
*/

int PlaceQueenMethodNum(int n) {

    if(n < 1) {
        return 0;
    }

    int *board = (int *)malloc(sizeof(int)*n);
    memset(board, -1, sizeof(int)*n);

    int sum = 0;
// 第i个棋子
    int i = 0;
    while (i >= 0) {
        board[i]++;
        while (board[i] < n && !check(board, i)) {
            board[i]++;
        }

        if (board[i] < n) {
            // 如果最后一个元素处理完了
            if (i == n - 1) {
                sum++;
            } else {
                // 处理下一个后
                i++;
                // 放在第一个位置
                board[i] = -1;
            }
        } else {
            // 返回到上一个棋子
            i--;
        }
    }

    return sum;
}
