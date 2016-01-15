#include <iostream>
#include "OJ.h"

using namespace std;

int main() {

    char input[] = "a123b12345c123456d123456789";
    char * p;

    cout << input << endl;

    unsigned int rs = Continumax(&p, input);

    cout << rs << ", " << cout << *p << ", "  << p << endl;

    rs = Continumax(&p, NULL);

    cout << rs << ", " << cout << *p << endl;

    return 0;
}
