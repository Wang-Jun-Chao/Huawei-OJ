#include <iostream>
#include "OJ.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;

    int p = 0;
    int rs = -1;

    rs = CalcSpeedOfCar(0, &p);
    cout << rs << " " << p << endl;

    rs = CalcSpeedOfCar(1, &p);
    cout << rs << " " << p << endl;

    rs = CalcSpeedOfCar(5, &p);
    cout << rs << " " << p << endl;

    rs = CalcSpeedOfCar(11, &p);
    cout << rs << " " << p << endl;

    rs = CalcSpeedOfCar(95859, &p);
    cout << rs << " " << p << endl;

    rs = CalcSpeedOfCar(998899, &p);
    cout << rs << " " << p << endl;

    rs = CalcSpeedOfCar(999999, &p);
    cout << rs << " " << p << endl;

    return 0;
}
