#ifndef __OJ_H__
#define __OJ_H__


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
	逆序输出结果    strRst
	逆序整数		iOutput

返回:
	0  成功
	-1 输入无效
*/

int ProcessX(int iInput, int& iNum, char * strRst, int& iOutput);

#endif
