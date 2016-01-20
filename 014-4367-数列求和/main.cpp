#include <iostream>
#include "OJ.h"
using namespace std;

int main() {

    double rst = 0;
    /*
        cout << fact(1) << endl;
        cout << fact(2) << endl;
        cout << fact(3) << endl;
        cout << fact(4) << endl;
        cout << fact(5) << endl;
    */
    GetResult(1, &rst);
    cout << rst << endl;
    GetResult(2, &rst);
    cout << rst << endl;
    GetResult(3, &rst);
    cout << rst << endl;
    GetResult(4, &rst);
    cout << rst << endl;
    GetResult(5, &rst);

    cout << rst << endl;
    return 0;
}
