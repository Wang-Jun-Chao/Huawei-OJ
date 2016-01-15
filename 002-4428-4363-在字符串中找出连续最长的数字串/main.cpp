#include <iostream>
#include "OJ.h"

using namespace std;

int main(){
    cout << "Hello world!" << endl;

    char * input = "a123b12345c123456d123456789";
    char ** p ;

    unsigned int rs =0;
    rs = Continumax(p, input);

    cout << rs << endl;
    cout << *p << endl;

    return 0;
}
