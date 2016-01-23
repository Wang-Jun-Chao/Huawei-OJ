#include <iostream>
#include "OJ.h"

using namespace std;

void testCase01() {
    int iRet = 0;
    std::string  sExpectedResult("2468642");
    std::string strResult = "";

    iRet = multiply("1111", "2222", strResult);
    cout << 0 << " "  << iRet << endl;
    cout <<sExpectedResult << " |" << strResult << "|" << endl;
}

void testCase02() {
    int iRet = 0;
    std::string  sExpectedResult("88871112");
    std::string strResult = "";

    iRet = multiply("9999", "8888", strResult);
    cout << 0 << " "  << iRet << endl;
    cout <<sExpectedResult << " |" << strResult  << "|" << endl;
}

void testCase03() {
    int iRet = 0;
    std::string  sExpectedResult("0");
    std::string strResult = "";

    iRet = multiply("0", "8888", strResult);
    cout << 0 << " "  << iRet << endl;
    cout <<sExpectedResult << " |" << strResult  << "|" << endl;
}

int main() {
    cout << "Hello world!" << endl;

    testCase01();
    testCase02();
    testCase03();

    return 0;
}
