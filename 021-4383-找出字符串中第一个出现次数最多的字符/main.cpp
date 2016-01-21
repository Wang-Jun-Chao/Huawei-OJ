#include <iostream>
#include "OJ.h"
using namespace std;



int main() {
    cout << "Hello world!" << endl;

    char arr[] = "!abcd ABCD!";
    char rst;
    bool bReturn;
    bReturn = FindChar(arr, &rst);

    cout << bReturn << " " << rst << endl;
    return 0;
}
