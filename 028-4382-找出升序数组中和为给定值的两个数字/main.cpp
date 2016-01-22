#include <iostream>
#include "OJ.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    int  aData[] = {1, 2, 4, 7, 11, 15};
	int  iNum1, iNum2;
	bool bReturn;

	bReturn = FindTwoNumbersWithSum(aData, 6, 15, &iNum1, &iNum2);

	cout << bReturn << " " << iNum1 << " " << iNum2 << endl;
    return 0;
}
