#include <iostream>
#include "OJ.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    char *pIn = "jkds*^*(HKEEEklIdddjilfff";
    char *pOut = "jkds*^*(HKEEEklIejilg";
    char pTest[200];
    int rst = 0;
    rst = ChangeString(pIn, pTest);

    cout << pIn << endl;
    cout << pOut << endl;
    cout << rst << endl;
    cout << pTest << endl;

    pIn = "jkds*^*(HKEEEklIddddjilffff";
    pOut = "jkds*^*(HKEEEklIejilg";
    ChangeString(pIn, pTest);

    cout << pIn << endl;
    cout << pOut << endl;
    cout << rst << endl;
    cout << pTest << endl;

    pIn = "jkds*^*(HKEEEklIddddjilzzzz";
    pOut = "jkds*^*(HKEEEklIejila";
    ChangeString(pIn, pTest);

    cout << pIn << endl;
    cout << pOut << endl;
    cout << rst << endl;
    cout << pTest << endl;

    pIn = "";
    pOut = "";
    ChangeString(pIn, pTest);

    cout << pIn << endl;
    cout << pOut << endl;
    cout << rst << endl;
    cout << pTest << endl;

    pIn = "aaaaaaaaa";
    pOut = "c";
    ChangeString(pIn, pTest);

    cout << pIn << endl;
    cout << pOut << endl;
    cout << rst << endl;
    cout << pTest << endl;

    return 0;
}
