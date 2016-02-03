#include <iostream>
#include "sqlist.h"

using namespace std;

void testCase01_1() {
    int maxNum = 5;
    char *outSeq = "34215";

    cout << 1 << " " << JudgeTrainSequence(maxNum, outSeq) << endl;

    return;
}

void testCase01_2() {
    int maxNum = 5;
    char *outSeq = "45321";

    cout << 1 << " " << JudgeTrainSequence(maxNum, outSeq) << endl;

    return;
}

void testCase01_3() {
    int maxNum = 5;
    char *outSeq = "35421";

    cout << 1 << " " << JudgeTrainSequence(maxNum, outSeq) << endl;

    return;
}

void testCase01_4() {
    int maxNum = 5;
    char *outSeq = "43512";

    cout << 0 << " " << JudgeTrainSequence(maxNum, outSeq) << endl;

    return;
}

void testCase01_5() {
    int maxNum = 5;
    char *outSeq = "35412";

    cout << 0 << " " << JudgeTrainSequence(maxNum, outSeq) << endl;

    return;
}

int main() {
    cout << "Hello world!" << endl;

    testCase01_1();
    testCase01_2();
    testCase01_3();
    testCase01_4();
    testCase01_5();

    return 0;
}
