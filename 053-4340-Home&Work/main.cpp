#include <iostream>
#include <stdlib.h>
#include "OJ.h"

using namespace std;

void testCase01()
{
	double Ret;
	int M = 4;
	int N = 20;
	int paper_type_value[][2] = {{4,10},{5,22},{10,3},{1,2}};
	GetMaxValue(M, N,paper_type_value, &Ret);

	cout << Ret << " " << (abs(37.00 - Ret) <= 0.01) << endl;
}


int main() {
    cout << "Hello world!" << endl;

    testCase01();

    return 0;
}
