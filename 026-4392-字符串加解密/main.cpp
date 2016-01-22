#include <iostream>

using namespace std;




int main() {


    char password[] = "Huawei1234";
 	char excepted[] = "iVBXFJ2345";
	char actual[101];

	Encrypt (password, actual);
	cout << password << endl << excepted << endl << actual << endl << endl;

	char UnEncryptPassword[101];

	unEncrypt (actual, UnEncryptPassword);
	cout << actual << endl << password << endl << UnEncryptPassword << endl << endl;

    return 0;
}
