#include <iostream>
#include "OJ.h"

using namespace std;

void testCase01() {
    cout << Game24Points(7, 2, 1, 10) << " " << true << endl;
}

void testCase02() {
    cout << Game24Points(1, 2, 3, 4)  << " " << true << endl;
}

void testCase03() {
    cout << Game24Points(7, 7, 7, 7)  << " " << false << endl;
}

void testCase04() {
    cout << Game24Points(1, 5, 5, 5)  << " " << true << endl;
}
int main() {
    cout << "Hello world!" << endl;
    testCase01();
    testCase02();
    testCase03();
    testCase04();
    return 0;
}
