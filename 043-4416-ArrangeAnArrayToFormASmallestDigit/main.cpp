#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "OJ.h"

using namespace std;

void testCase01() {
    int a[] = {2,1};
    char szRst[10]  = {0};
    char *strExpect = "12";
    smallestDigit(a, 2, szRst);
    cout << szRst << " " << strExpect << endl;
    cout << 0 << " " << strcmp(szRst,strExpect) << endl;
}

void testCase02() {
    int a[] = {32, 321};
    char szRst[10]  = {0};
    char *strExpect = "32132";
    smallestDigit(a, 2, szRst);
    cout << szRst << " " << strExpect << endl;
    cout << 0 << " " << strcmp(szRst,strExpect) << endl;
}

void testCase03() {
    int a[] = {4589, 101,41425,9999};
    char szRst[20]  = {0};
    char *strExpect = "1014142545899999";
    smallestDigit(a, 4, szRst);
    cout << szRst << " " << strExpect << endl;
    cout << 0 << " " << strcmp(szRst,strExpect) << endl;
}


void testCase04() {
    int a[] = {1, 2, 3, 1, 2, 3, 11, 22, 33};
    char szRst[20]  = {0};
    char *strExpect = "111122223333";
    smallestDigit(a, 9, szRst);
    cout << szRst << " " << strExpect << endl;
    cout << 0 << " " << strcmp(szRst,strExpect) << endl;
}

int main() {
    cout << "Hello world!" << endl;

    testCase01();
    testCase02();
    testCase03();
    testCase04();


    return 0;
}
