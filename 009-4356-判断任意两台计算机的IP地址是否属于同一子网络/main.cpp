#include <iostream>
#include <stdlib.h>
#include "OJ.h"

using namespace std;
/*
int * IpStringToIpInt(char * pIp) {
    int *rs = (int *)malloc(4*sizeof(int));

    char * p = pIp;
    int cnt = 0;

    while(*p != '\0') {

        if(*p != '0' && *p != '.') {
            int digit = 0;

            while(*p != '\0' && *p != '.') {
                digit = digit * 10 + (*p - '0');
                p++;
            }
            // cout << digit << endl;

            rs[cnt] = digit;
            cnt++;
        } else {
            p++;
        }
    }

    return rs;
}

int IsSameSubNetwork(char * pcIp1, char * pcIp2, char * pcSubNetworkMask) {

    int * ip1 = IpStringToIpInt(pcIp1);
    int * ip2 = IpStringToIpInt(pcIp2);
    int * mask = IpStringToIpInt(pcSubNetworkMask);

    for(int i = 0; i < 4; i++) {
        if((pcIp1[i]&pcSubNetworkMask[i]) != (pcIp2[i]&pcSubNetworkMask[i])) {
            return 0;
        }
    }

    free(ip1);
    free(ip2);
    free(mask);

    return 1;
}
*/
int main() {
    cout << "Hello world!" << endl;
    char * num = "123456";

    //cout << StringToInt(num, num + 5) << endl;

    char * ip1 = "192.168.0.1";
    char * ip2 = "192.168.0.254";
    char * mask = "255.255.255.0";
    int rs;

    rs = IsSameSubNetwork(ip1, ip2, mask);
    cout << rs << endl;

    ip1 = "192.168.0.1";
    ip2 = "92.168.0.254";
    mask = "255.255.255.0";

    rs = IsSameSubNetwork(ip1, ip2, mask);
    cout << rs << endl;
    return 0;
}
