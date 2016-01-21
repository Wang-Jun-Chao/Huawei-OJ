#include <iostream>
#include "OJ.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;

    char strInput[] = "ABCDEF";
	char strSrc[] = "FEDCBA";
	char strOutput[10] = "";
	ProcessString(strInput, strOutput);

	cout << strInput << " " << strOutput << endl;

    return 0;
}
