#include <iostream>
#include "IPAddressValid.h"

using namespace std;
void testCase01() {
    const char* pazIPAddress = "127.0.0.1";

    bool isIP = isIPAddressValid(pazIPAddress);
    cout << isIP << " "  << true << endl;
}


void testCase02() {
    const char* pazIPAddress = "01.1.1.1";

    bool isIP = isIPAddressValid(pazIPAddress);
    cout << isIP << " "  << false << endl;
}

void testCase03() {
    const char* pazIPAddress = "1.02.3.4";

    bool isIP = isIPAddressValid(pazIPAddress);
    cout << isIP << " "  << false << endl;
}

void testCase04() {
    const char* pazIPAddress = "0.0.0.0";

    bool isIP = isIPAddressValid(pazIPAddress);
    cout << isIP << " "  << true << endl;
}

void testCase05() {
    const char* pazIPAddress = "0.00.0.0";

    bool isIP = isIPAddressValid(pazIPAddress);
    cout << isIP << " "  << 1 << endl;
}

void testCase06() {
    const char* pazIPAddress = " 1.2.3.4";

    bool isIP = isIPAddressValid(pazIPAddress);
    cout << isIP << " "  << true << endl;
}

void testCase07() {
    const char* pazIPAddress = "1.2.3.4 ";

    bool isIP = isIPAddressValid(pazIPAddress);
    cout << isIP << " "  << true << endl;
}

void testCase08() {
    const char* pazIPAddress = " 1.2.3.4 ";

    bool isIP = isIPAddressValid(pazIPAddress);
    cout << isIP << " "  << true << endl;
}

void testCase09() {
    const char* pazIPAddress = " 1.2a.3.4 ";

    bool isIP = isIPAddressValid(pazIPAddress);
    cout << isIP << " "  << false << endl;
}

void testCase10() {
    const char* pazIPAddress = " 1.256.3.4 ";

    bool isIP = isIPAddressValid(pazIPAddress);
    cout << isIP << " "  << false << endl;
}

void testCase11() {
    const char* pazIPAddress = " 1.255..3.4 ";

    bool isIP = isIPAddressValid(pazIPAddress);
    cout << isIP << " "  << false << endl;
}

void testCase12() {
    const char* pazIPAddress = " 1.255.3 ";

    bool isIP = isIPAddressValid(pazIPAddress);
    cout << isIP << " "  << false << endl;
}

void testCase13() {
    const char* pazIPAddress = "1.2.3 .4";

    bool isIP = isIPAddressValid(pazIPAddress);
    cout << isIP << " "  << false << endl;
}

void testCase14() {
    const char* pazIPAddress = "1.2. 3.4";

    bool isIP = isIPAddressValid(pazIPAddress);
    cout << isIP << " "  << false << endl;
}

void testCase15() {
    const char* pazIPAddress = "1.2.00.4";

    bool isIP = isIPAddressValid(pazIPAddress);
    cout << isIP << " "  << true << endl;
}

int main() {
    cout << "Hello world!" << endl;

       testCase01();
        testCase02();
        testCase03();
        testCase04();
        testCase05();
        testCase06();
        testCase07();
        testCase08();


        testCase09();
        testCase10();
        testCase11();
        testCase12();


    //testCase13();
    testCase14();
    testCase15();

    return 0;
}
