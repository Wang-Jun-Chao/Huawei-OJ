#include <iostream>
#include "OJ.h"

using namespace std;

int main() {

    char str[256];
    int rst = 0;
    rst = removechars("helloworld", 'c', str);

    cout << rst << " |" << str << "|" << endl;


    removechars("ccccccccc", 'c', str);
    cout << rst << " |" << str << "|" << endl;
    return 0;
}
