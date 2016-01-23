#include <iostream>
#include <stdlib.h>
#include "OJ.h"

using namespace std;

void testCase01() {
    char *p;

    p = (char *)malloc(1000);
    CalcNN(13, p);
    cout << 13 << " " << p << " " << "6227020800" << endl;
    free(p);
}


int main() {
    cout << "Hello world!" << endl;

    testCase01();

    return 0;
}
