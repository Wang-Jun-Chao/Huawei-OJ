#include <iostream>
#include "OJ.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    int iInput = 23546;
    int iNum = 0;
    char strRst[11] = "";
    int iOutput = 0;

    ProcessX(iInput, iNum, strRst, iOutput);
    cout << iInput << ' ' << iNum << " |" << strRst << "| " << iOutput << endl;

    iInput = -23546;
    ProcessX(iInput, iNum, strRst, iOutput);
    cout << iInput << ' ' << iNum << " |" << strRst << "| " << iOutput << endl;


    iInput = 1;
    ProcessX(iInput, iNum, strRst, iOutput);
    cout << iInput << ' ' << iNum << " |" << strRst << "| " << iOutput << endl;

    iInput = -1;
    ProcessX(iInput, iNum, strRst, iOutput);
    cout << iInput << ' ' << iNum << " |" << strRst << "| " << iOutput << endl;

    iInput = 0;
    ProcessX(iInput, iNum, strRst, iOutput);
    cout << iInput << ' ' << iNum << " |" << strRst << "| " << iOutput << endl;

    iInput = 123;
    ProcessX(iInput, iNum, strRst, iOutput);
    cout << iInput << ' ' << iNum << " |" << strRst << "| " << iOutput << endl;

    iInput = -123;
    ProcessX(iInput, iNum, strRst, iOutput);
    cout << iInput << ' ' << iNum << " |" << strRst << "| " << iOutput << endl;

    return 0;
}
