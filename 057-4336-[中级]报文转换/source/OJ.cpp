#include <stdlib.h>
#include "oj.h"

/*
功能:
    将给定的报文按规则转换成另一个报文后输出。
    转换规则如下：
    报文中如果出现0x7E，转义成为2个字节0x7D 0x5E，如果出现0x7D，转义成为2个字节0x7D 0x5D。最后在报文头尾各加上一个0x7E定界。

    示例（每个字节以十六进制数表示）
    给定原始报文：1D 2B 3C 4D 5E 7E 6F 7D 7E
    转换后的报文：7E 1D 2B 3C 4D 5E 7D 5E 6F 7D 5D 7D 5E 7E

输入:
char* pInput: 给定的输入报文，内存空间由调用者申请和释放
int iLen: 给定报文的长度
输出:
char* pOutput：转换后的报文，内存空间由调用者申请和释放
返回:
int： 成功 0， 失败 -1

*/

int PktTrans(char* pInput, int iLen, char* pOutput) {

    if(pInput == NULL || pOutput == NULL || iLen < 1) {
        return -1;
    }

    int idx = 0;
    pOutput[idx++] = 0x7E;

    for(int i = 0; i < iLen; i++) {

        if(pInput[i] == 0x7E) {
            pOutput[idx++] = 0x7D;
            pOutput[idx++] = 0x5E;
        } else if(pInput[i] == 0x7D) {
            pOutput[idx++] = 0x7D;
            pOutput[idx++] = 0x5D;
        } else {
            pOutput[idx++] = pInput[i];
        }
    }

    pOutput[idx] = 0x7E;
    return 0;
}
