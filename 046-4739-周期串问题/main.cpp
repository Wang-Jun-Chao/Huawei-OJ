#include <iostream>
#include "OJ.h"

using namespace std;

void testCase01() {
    int iRet;

    char inputstring[13] = "abcabcabcabc";

    iRet = GetMinPeriod(inputstring);

    cout << iRet << " " << 3 << endl;
}

void testCase02() {
    int iRet;

    char inputstring[13] = "aaaaa";

    iRet = GetMinPeriod(inputstring);

    cout << iRet << " " << 1 << endl;
}

void testCase03() {
    int iRet;

    char inputstring[13] = "aaaab";

    iRet = GetMinPeriod(inputstring);

    cout << iRet << " " << 5 << endl;
}


void testCase04() {
    int iRet;

    char inputstring[13] = "123456789";

    iRet = GetMinPeriod(inputstring);

    cout << iRet << " " << 9 << endl;
}

int main() {
    cout << "Hello world!" << endl;

    testCase01();
    testCase02();
    testCase03();
    testCase04();


    return 0;
}
