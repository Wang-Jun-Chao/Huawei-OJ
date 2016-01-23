#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "OJ.h"

using namespace std;

void testCase01() {
    int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int C[3][3], ExpectC[3][3] = {{30, 36, 42}, {66, 81, 96}, {102, 126, 150}};

    matrix((int**)A, (int**)A, (int**)C, 3);

    cout << 0 << " " << memcmp(C, ExpectC, sizeof(C)) << endl;
}

int main() {
    cout << "Hello world!" << endl;
    testCase01();


    return 0;
}
