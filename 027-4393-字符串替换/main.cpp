#include <iostream>
#include "OJ.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;

    char strInput[] = "d545a";
	char strSrc[] = "d545c";
	char strOutput[10] = "";
	ProcessString(strInput,'a','c',strOutput);
    cout << strInput << endl << strOutput << endl << strSrc << endl << endl;

    char strInput2[] = "ABCDEF";
    char strOutput2[] = "BBCDEF";
    char strSrc2[10] = "";
    ProcessString(strInput2,'A','B',strOutput2);
    cout << strInput2 << endl << strOutput2 << endl << strSrc2 << endl << endl;
    return 0;
}
