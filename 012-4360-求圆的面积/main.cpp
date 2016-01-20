#include <iostream>
#include "OJ.h"
using namespace std;

int main() {

    float arrValue[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int num = 9;
    OutputRotundityArea(arrValue, num);

    for(int i = 0; i < num; i++) {
        cout << arrValue[i] << endl;
    }

    return 0;
}
