#include <iostream>
#include "OJ.h"

using namespace std;

void testCase01() {
    char result[1024] = {0};
    int rst = GetResult("abadcbad", result);
    cout << rst << " " << result << " " << "abdc" << endl;
}

int main() {
    cout << "Hello world!" << endl;

    testCase01();

    return 0;
}
