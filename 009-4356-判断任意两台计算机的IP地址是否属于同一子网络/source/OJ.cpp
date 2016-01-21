#include <stdlib.h>
#include <string.h>
#include "OJ.h"



/*
功能: 判断两台计算机IP地址是同一子网络。
原型：
    int IsSameSubNetwork(char * pcIp1, char * pcIp2, char * pcSubNetworkMask);

输入参数：
    char * pcIP1: 计算机1的IP地址，格式：“192.168.0.254”；
    char * pcIP2: 计算机2的IP地址，格式：“192.168.0.1”；
    char * pcSubNetworkMask: 子网掩码，格式：“255.255.255.0”；

返回值：
    0：IP1与IP2不属于同一子网络；
    1：IP1与IP2属于同一子网络；
*/

int getIP(char * chpcIP, unsigned int * npcIP) {
    // 记录处理的位置
    int i = 0;
    // 当前的IP数字部分
    char * temp;
    // 当前的IP数字部分的长度
    int tempCnt = 0;
    // 当前处理的第多少个IP部分
    int cntIP = 0;
    // IP字符串的长度
    int lenIP = strlen(chpcIP);

    for (i = 0; i <= lenIP; i++) {
        // 说明处理到了某部分的结束位置
        if((chpcIP[i] == '.') || (chpcIP[i] == '\0')) {
            // 分配内存
            temp = (char*)malloc(tempCnt * sizeof(char));
            // 赋值
            memcpy(temp, chpcIP + i - tempCnt, tempCnt);
            // 将数字符串转成整形
            npcIP[cntIP] = atoi(temp);
            // 释放内存空间
            free(temp);
            // 记录下一个IP部分部分
            cntIP++;
            // 长度归0
            tempCnt = 0;
        } else {
            tempCnt++;
        }
    }
    return 0;
}

int IsSameSubNetwork(char * pcIp1, char * pcIp2, char * pcSubNetworkMask) {
    /*在这里实现功能*/
    int flag = 1;
    int i = 0;
    unsigned int ip1[4] = {0};
    unsigned int ip2[4] = {0};
    unsigned int mask[4] = {0};
    getIP(pcIp1, ip1);
    getIP(pcIp2, ip2);
    getIP(pcSubNetworkMask,mask);

    for (i = 0; i < 4; i++) {
        if ((ip1[i] & mask[i]) != (ip2[i] & mask[i])) {
            flag = 0;
        }
    }
    return flag;
}
