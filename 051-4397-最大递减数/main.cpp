#include <iostream>
#include "Degressive.h"

using namespace std;

void testCase01()
{
	cout << getMaxDegressiveNum(95345323) << " " << 953 << endl;
	cout << getMaxDegressiveNum(0) << " " << 0 << endl;
	cout << getMaxDegressiveNum(2) << " " << 2 << endl;
	cout << getMaxDegressiveNum(5) << " " << 5 << endl;

	cout << getMaxDegressiveNum(65987) << " " <<987 << endl;

	cout << getMaxDegressiveNum(1111) << " " << 1 << endl;
	cout << getMaxDegressiveNum(11112222) << " " << 2 << endl;
	cout << getMaxDegressiveNum(22221111) << " " << 21 << endl;

}

int main() {
    cout << "Hello world!" << endl;

    testCase01();

    return 0;
}
