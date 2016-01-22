#include <iostream>
#include "OJ.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;

    char strInput[] = "d545a";
	char strSrc[] = "d545c";
	char strOutput[10] = "";
	int rst = 0;
	ProcessString(strInput,'a','c',strOutput);
    cout << strInput << endl << strOutput << endl << strSrc << endl << rst << endl << endl;

    char strInput2[] = "ABCDEF";
    char strOutput2[] = "BBCDEF";
    char strSrc2[10] = "";
    ProcessString(strInput2,'A','B',strOutput2);
    cout << strInput2 << endl << strOutput2 << endl << strSrc2 << endl << rst << endl << endl;

    char strInput3[] = "";
    char strOutput3[] = "";
    char strSrc3[10] = "";
    ProcessString(strInput3,'A','B',strOutput3);
    cout << strInput3 << endl << strOutput3 << endl << strSrc3 << endl << rst << endl << endl;

    char strInput4[] = "";
    char strOutput4[] = "";
    char strSrc4[10] = "";
    ProcessString(strInput4,'A','B',strOutput4);
    cout << strInput4 << endl << strOutput4 << endl << strSrc4 << endl << rst << endl << endl;
    return 0;
}
