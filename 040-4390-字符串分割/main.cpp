#include <iostream>
#include "OJ.h"

using namespace std;

void testCase01()
{
	AddString("434353f");
	AddString("ABCDEFG1234");
	AddString("1234567890");

	printMatrix();

	char strRst[][9] = {"434353f0","ABCDEFG1","23400000","12345678","90000000"};

	cout << (5 == GetLength()) << endl;
	cout << (0 == ArrCmp(strRst,5)) << endl;
}

void testCase02()
{

	AddString("1234567891234567");

	printMatrix();

	char strRst[][9] = {"12345678", "91234567"};

	cout << (2 == GetLength()) << endl;
	cout << (0 == ArrCmp(strRst,2)) << endl;
}

void testCase03()
{

	AddString("");

	printMatrix();

	char strRst[][9] = {"00000000"};

	cout << (1 == GetLength()) << endl;
	cout << (0 == ArrCmp(strRst,1)) << endl;
}

int main() {
    cout << "Hello world!" << endl;

    //testCase01();
    testCase02();
   // testCase03();

    return 0;
}
