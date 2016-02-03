#include <iostream>
#include <string.h>
#include "OJ.h"

using namespace std;

void testCase01() {
    char szInput[100] =  {0x1D, 0x2B, 0x3C, 0x4D, 0x5E, 0x7E, 0x6F, 0x7D, 0x7E};
    char szResult[100] = {0x7E, 0x1D, 0x2B, 0x3C, 0x4D, 0x5E, 0x7D, 0x5E, 0x6F, 0x7D, 0x5D, 0x7D, 0x5E, 0x7E};
    char szOutput[100] = {0};



    cout << 0 << " " << PktTrans(szInput, 9, szOutput) << endl;
    cout << 0 << " " << strncmp(szResult, szOutput, 14) << endl;

    for(int i =0; i < 14; i++) {
        cout << szResult[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < 14; i++) {
        cout << szOutput[i] << " ";
    }
    cout << endl;

    return;
}

void testCase02() {
    char szInput[100] =  {0x1D, 0x2B, 0x3C, 0x4D, 0x5E, 0x7E, 0x6F, 0x7D, 0x7E};
    char szResult[100] = {0x7E, 0x1D, 0x2B, 0x3C, 0x4D, 0x5E, 0x7D, 0x5E, 0x6F, 0x7D, 0x5D, 0x7D, 0x5E, 0x7E};
    char szOutput[100] = {0};

    cout << -1 << " " << PktTrans(NULL, 9, szOutput) << endl;
    cout << -1 << " " << PktTrans(szInput, 0, szOutput) << endl;
    cout << -1 << " " << PktTrans(szInput, 9, NULL) << endl;


    return;
}

void testCase03() {
    char szInput[100] =  {0x7D, 0x7E};
    char szResult[100] = {0x7E, 0x7D, 0x5D, 0x7D, 0x5E, 0x7E};
    char szOutput[100] = {0};

    cout << 0 << " " << PktTrans(szInput, 2, szOutput) << endl;
    cout << 0 << " " << strncmp(szResult, szOutput, 6) << endl;

    for(int i =0; i < 6; i++) {
        cout << szResult[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < 6; i++) {
        cout << szOutput[i] << " ";
    }
    cout << endl;

    return;
}

int main() {
    cout << "Hello world!" << endl;

    testCase01();
    // testCase02();
    testCase03();
    return 0;
}
