#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "OJ.h"

using namespace std;

int main() {

    char input[] = "a123b12345c123456d123456789";
    char * p = NULL;
    unsigned int rs  = 0;

    cout << input << endl;
    cout << &p << " " << (p == NULL ? "null" : p) << endl;

    rs = Continumax(&p, NULL);
    //cout << rs << ", " << &p << ", |" << p << "|" <<endl;
/*
    rs = Continumax(&p, input);
    cout << rs << ", " << &p << ", |" << p << "|" <<endl;


    char input2[] = "abcd12345ed125ss123058789";
    char * p2 = NULL;
    unsigned int rs2 = Continumax(&p2, input2);
    cout << rs2 << ", " << &p2 << ", " << p2 << endl;

    char input3[] = "abcd12345ss54761";
    char * p3 = NULL;
    rs = Continumax(&p3, input3);
    cout << rs << ", " << &p3 << ", " << p3 << endl;

    char input4[] = "123456789abcd12345ss54761";
    char * p4 = NULL;
    rs = Continumax(&p4, input4);
    cout << input4 << ", " << rs << ", " << &p4 << ", " << p4 << endl;

    char input5[] = "";
    char * p5 = NULL;
    rs = Continumax(&p5, input5);
    cout << input5 << ", " << rs << ", " << &p5 << ", " << p5 << endl;

    char input6[] = "123456789";
    char * p6 = NULL;
    rs = Continumax(&p6, input6);
    cout << input6 << ", " << rs << ", " << &p6 << ", " << p6 << endl;

    char* intputstr = "abcd12345ed125ss123456789" ;
    char *pOutputstr = NULL;
    unsigned int nLength = Continumax(&pOutputstr, intputstr);
    cout << nLength << " " << pOutputstr << endl;
*/
    return 0;
}
