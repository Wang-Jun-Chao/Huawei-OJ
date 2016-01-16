#include <iostream>

using namespace std;

int StringToInt(char * pBeg, char * pEnd) {

    int rs = 0;

    while(pEnd >= pBeg) {
        rs = rs*10 + (*pEnd) - '0';
        pEnd--;
    }

    return rs;
}

int * IpStringToIpInt(char * pIp) {
    int rs[4] = {0};

    char * pBeg = pIp;
    char * pEnd = pIp;
    int cnt = 0;

    while(*pEnd != '\0') {
        while(*pEnd != '\0' && *pEnd != '.') {
            pEnd++;
        }



        cout << StringToInt(pBeg, pEnd - 1) << endl;
        rs[cnt] = StringToInt(pBeg, pEnd - 1);
        cnt++;
        pBeg = pEnd + 1;
    }

    pBeg = NULL;
    pEnd = NULL;

    return rs;
}

int IsSameSubNetwork(char * pcIp1, char * pcIp2, char * pcSubNetworkMask) {
    for(int i = 0; i < 4; i++) {
        if((pcIp1[i]&pcSubNetworkMask[i]) != (pcIp2[i]&pcSubNetworkMask[i])) {
            return 1;
        }
    }

    return 0;
}

int main() {
    cout << "Hello world!" << endl;
    char * num = "123456";

    cout << StringToInt(num, num + 5) << endl;

    char * ip = "192.126.215.12";
    int * rs = IpStringToIpInt(ip);

    for(int i = 0; i < 4; i++) {
        cout << rs[i] << " ";
    }

    return 0;
}
