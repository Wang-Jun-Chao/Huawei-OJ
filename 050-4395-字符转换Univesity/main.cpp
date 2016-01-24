#include <iostream>
#include "OJ.h"

using namespace std;

void testCase01()
{
	char szSource[] = "Ilttabaje zaujljg#";
 	char szResult[] = "Different meaning#";
	char* pResult = CharReplace(szSource);
 	cout << szResult << endl << pResult << endl << endl;
}

void testCase02()
{
	char *szSource = NULL;
 	char *szResult = NULL;
	char* pResult = CharReplace(NULL);
 	cout << szResult << endl << pResult << endl << endl;
}

int main() {
    cout << "Hello world!" << endl;

    testCase01();
    return 0;
}
