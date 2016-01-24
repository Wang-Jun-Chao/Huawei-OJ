#include "IPAddressValid.h"

bool ipToInt(char * b, char * e, int &rst) {

    // IP地址部分有前导0
    if(b - e > 1 && *b == '0') {
        return false;
    }


    char *t = b;
    rst = 0;
    while( t <= e) {

        if(*t >= '0' && *t <= '9') {
            rst = rst * 10 + (*t - '0');
        } else {
            return false;
        }
    }

    if(rst >= 0 && rst < 256) {
        return true;
    }

    return false;


}

bool isIPAddressValid(const char* pszIPAddr) {

    int idx = 0;

    while()

    return true;
}
