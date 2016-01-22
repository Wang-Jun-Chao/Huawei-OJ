#include <stdlib.h>
#include "oj.h"
#include <vector>
#include <string>

using namespace std;

// 求取整数的各位 以及 逆序整数
vector<int> AllNum(int num,int &reverseNum) {
    vector<int> result;
    if(num == 0) {
        result.push_back(0);
        return result;
    }
    reverseNum = 0;
    int tmp = num;
    int c;
    while(tmp) {
        c = tmp % 10;
        result.push_back(c);
        reverseNum = reverseNum * 10 + c;
        tmp /= 10;
    }
    return result;
}

/*
功能:
	给出一个不多于5位的整数，
	要求:
		1、求出它是几位数
		2、分别输出每一位数字
		3、按逆序输出各位数字，例如原数为321,应输出123
输入:
	整型 iInput,位数不大于5的整数

输出:
    整数位数		iNum
	空格间隔输出结果    strRst
	逆序整数		iOutput

返回:
	0  成功
	-1 输入无效
*/

int ProcessX(int iInput, int& iNum, char * strRst, int& iOutput){
    // 参数检验
    if(strRst == NULL){
        return -1;
    }


    // 负数
    bool positive = true;
    // 标记是否为负数，并且把负数变成正数
    if(iInput < 0){
        positive = false;
        iInput = -iInput;
    }

    // 求整数上的各位数，并且求出它的翻转数
    vector<int> vec = AllNum(iInput,iOutput);

    // 求出它是几位数
    iNum = vec.size();

    // 负数情况
    int index = 0;
    if(!positive){
        iOutput = -iOutput;
        strRst[index++] = '-';
    }

    // 按格式分别输出每一位数字
    for(int i = iNum - 1;i >= 0;--i){
        if(i == iNum - 1){
            strRst[index++] = vec[i] + '0';
        }
        else{
            strRst[index++] = ' ';
            strRst[index++] = vec[i] + '0';
        }
    }
    strRst[index] = '\0';

    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////

// 下面的方法末能通过全部测试用例
// 但是在测试过程中使用的输出和上面的方法一致，不知道未通过的测试用例的数据是什么
int ProcessX2(int iInput, int& iNum, char * strRst, int& iOutput) {

    if(strRst == NULL) {
        return -1;
    }

    iNum = 0;
    iOutput = 0;
    int isNagetive = 0;
    if(iInput < 0) {
        isNagetive = 1;
        // 变成正数
        iInput *= -1;
    }

    do {
        int v = iInput % 10;
        iInput /= 10;

        strRst[2*iNum + isNagetive] = (char)('0' + v);
        strRst[2*iNum + isNagetive + 1] = ' ';
        iOutput = 10*iOutput + v;
        iNum++;

    } while(iInput != 0);

    strRst[2*iNum + isNagetive - 1] = '\0';

    if(isNagetive == 1) {
        strRst[0] = '-';
        iOutput *= -1;
    }

    return 0;
}
