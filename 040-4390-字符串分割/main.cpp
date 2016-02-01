#include <iostream>
#include "OJ.h"

using namespace std;

void testCase01()
{
	AddString("434353f");
	AddString("ABCDEFG1234");
	AddString("1234567890");
	//AddString("12345678");

	//printMatrix();

	char strRst[][9] = {"434353f0","ABCDEFG1","23400000","12345678","90000000"};

	cout << (5 == GetLength()) << endl;
	cout << (0 == ArrCmp(strRst,5)) << endl;
}

int main() {
    cout << "Hello world!" << endl;

    testCase01();

    return 0;
}
