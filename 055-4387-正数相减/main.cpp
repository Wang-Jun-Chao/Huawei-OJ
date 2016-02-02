#include <iostream>
#include "Decrease.h"

using namespace std;
void testCase01() {
    char minuend[] = "85";
    char subtrahend[] = "79";
    char * ret;
    Decrease(minuend, subtrahend, &ret);
    cout << ret << " = 6" << endl;

}

void testCase02() {
    char minuend[] = "8.5";
    char subtrahend[] = "0.91";
    char * ret;
    Decrease(minuend, subtrahend, &ret);
    cout << ret << " = 7.59" << endl;
}

void testCase03() {
    char minuend[] = "8.5";
    char subtrahend[] = "7.5";
    char * ret;
    Decrease(minuend, subtrahend, &ret);
    cout << ret << " = 1" << endl;
}

void testCase04() {
    char minuend[] = "12.34";
    char subtrahend[] = "17.24";
    char * ret;
    Decrease(minuend, subtrahend, &ret);
    cout << ret << " = -4.9" << endl;
}

void testCase05() {
    char minuend[] = "12.340000";
    char subtrahend[] = "17.240000";
    char * ret;
    Decrease(minuend, subtrahend, &ret);
    cout << ret << " = -4.9" << endl;
}

void testCase06() {
    char minuend[] = "12.0000";
    char subtrahend[] = "17.000";
    char * ret;
    Decrease(minuend, subtrahend, &ret);
    cout << ret << " = -5" << endl;
}

void testCase07() {
    char minuend[] = "-12.0000";
    char subtrahend[] = "17.000";
    char * ret;
    Decrease(minuend, subtrahend, &ret);
    cout << ret << " = -29" << endl;
}

void testCase08() {
    char minuend[] = "-12.0000";
    char subtrahend[] = "-17.000";
    char * ret;
    Decrease(minuend, subtrahend, &ret);
    cout << ret << " = 5" << endl;
}

void testCase09() {
    char minuend[] = "12.0000";
    char subtrahend[] = "-17.000";
    char * ret;
    Decrease(minuend, subtrahend, &ret);
    cout << ret << " = 29" << endl;

}

void testCase10() {
    char minuend[] = "012.0000";
    char subtrahend[] = "-017.000";
    char * ret;
    Decrease(minuend, subtrahend, &ret);
    cout << ret << " = 29" << endl;
}

void testCase11() {
    char minuend[] = "0012.00100";
    char subtrahend[] = "-0017.0010";
    char * ret;
    Decrease(minuend, subtrahend, &ret);
    cout << ret << " = 29.002" << endl;
}

void testCase12() {
    char minuend[] = "1";
    char subtrahend[] = "-9999";
    char * ret;
    Decrease(minuend, subtrahend, &ret);
    cout << ret << " = 10000" << endl;
}
int main() {
    cout << "Hello world!" << endl;

    //testCase01();
    // testCase02();
    // testCase03();
   // testCase04();
   // testCase05();
    //testCase06();
    //testCase07();
   // testCase08();
    //testCase09();
    //testCase10();
   // testCase11();
    testCase12();

    return 0;
}
