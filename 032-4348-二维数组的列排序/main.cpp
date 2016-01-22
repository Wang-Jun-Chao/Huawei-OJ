#include <iostream>
#include "OJ.h"

using namespace std;

bool CmpArray(int * pRet,int * pResult,unsigned int m,unsigned int n) {
    for (unsigned int i = 0; i < m*n; ++i) {
        if (*(pResult+i) != *(pRet+i)) {
            return false;
        }
    }
    return true;

}

void test01() {
    int pArray[2][4] = {2,3,4,5,3,7,8,10};
    int RetArray[2][4] = {2,3,4,5,3,7,8,10};
	RangeArray(&pArray[0][0],2,4,1);
	cout << (CmpArray(&RetArray[0][0],&pArray[0][0],2,4)) << endl;
}

void test02() {
	int pArray2[2][4] = {
	    3,3,4,5,
	    2,7,8,10};
    int RetArray2[2][4] = {
        2,7,8,10,
        3,3,4,5};

    RangeArray(&pArray2[0][0],2,4,1);

    for(int i = 0; i < 8; i++) {
        cout << (&pArray2[0][0])[i] << " ";
    }

    cout << endl;
	cout << (CmpArray(&RetArray2[0][0],&pArray2[0][0],2,4)) << endl;
}

void test03() {

	int pArray2[2][4] = {
	    3,3,8,5,
	    2,3,5,10};
    int RetArray2[2][4] = {
        2,3,5,10,
        3,3,8,5};

    RangeArray(&pArray2[0][0],2,4,1);

    for(int i = 0; i < 8; i++) {
        cout << (&pArray2[0][0])[i] << " ";
    }

    cout << endl;
	cout << (CmpArray(&RetArray2[0][0],&pArray2[0][0],2,4)) << endl;
}

void test04() {

	int pArray2[2][4] = {
	    3,3,5,10,
	    2,3,5,5};
    int RetArray2[2][4] = {
        2,3,5,5,
        3,3,5,10};

    RangeArray(&pArray2[0][0],2,4,1);

    for(int i = 0; i < 8; i++) {
        cout << (&pArray2[0][0])[i] << " ";
    }

    cout << endl;
	cout << (CmpArray(&RetArray2[0][0],&pArray2[0][0],2,4)) << endl;
}
int main() {
    cout << "Hello world!" << endl;

    //test03();
    test04();






    return 0;
}
