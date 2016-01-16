
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
/*
int IsSameSubNetwork(char * pcIp1, char * pcIp2, char * pcSubNetworkMask) {
    for(int i = 0; i < 4; i++) {
        if((pcIp1[i]&pcSubNetworkMask[i]) != (pcIp2[i]&pcSubNetworkMask[i])) {
            return 1;
        }
    }

    return 0;
}

*/

