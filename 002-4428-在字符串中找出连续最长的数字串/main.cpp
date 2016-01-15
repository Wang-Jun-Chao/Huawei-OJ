#include <iostream>
#include <iomanip>
#include "OJ.h"

using namespace std;

int main() {

    char input[] = "a123b12345c123456d123456789";
    char * p;

    cout << input << endl;

    unsigned int rs = Continumax(&p, NULL);
    cout << rs << ", " << &p << ", |" << p << "|" <<endl;

    rs = Continumax(&p, input);
     cout << rs << ", " << &p << ", |" << p << "|" <<endl;

    rs = Continumax(&p, NULL);
    cout << rs << ", " << &p << ", |" << p << "|" <<endl;
/*
    char input2[] = "abcd12345ed125ss123058789";
    char * p2;
    unsigned int rs2 = Continumax(&p2, input2);
    cout << rs2 << ", " << &p2 << ", " << p2 << endl;

    char input3[] = "abcd12345ss54761";
    rs = Continumax(&p, input3);
    cout << rs << ", " << &p << ", " << p << endl;
*/
    return 0;
}
