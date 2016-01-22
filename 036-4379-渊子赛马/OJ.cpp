#include <algorithm>
#include "OJ.h"

using namespace std;

/*
功能:判断yuanzi 的马是否会赢？yuanzi 的马赢了，返回 YES. 否则返回 NO

输入参数：
unsigned int num: 赛马的数量；   (1<= num <=1000)
unsigned int * speed_yz: yuanzi 的马的速度；
unsigned int * speed_op: 对手的马的速度；
输出参数：
	 	无
返回值：
		char * 型 的字符串，yuanzi 的马赢了，返回 YES. 否则返回 NO；

*/

char * IsYuanziWin(unsigned int num, unsigned int * speed_yz, unsigned int * speed_op) {

    if(num < 1 || speed_yz == NULL || speed_op == NULL) {
        return "NO";
    }

    sort(speed_yz, speed_yz + num);
    sort(speed_op, speed_op + num);

    int count = 0;

    int idx = num- 1;
    for (int i = num - 1; i >= 0; i--) {

        // 在idx位置向前找，批speedYz[i]速度慢的马
        while (idx >= 0 && speed_yz[i] <= speed_op[idx]) {
            idx--;
        }
        // 找到所求的马，就可以赢得比赛
        if (idx >= 0) {
            count++;
            // speedOp中下一次要找的马
            idx--;
            if (count > num / 2) {
                return "YES";
            }
        }
    }

    return "NO";
}


