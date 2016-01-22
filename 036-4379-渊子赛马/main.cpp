#include <iostream>
#include "OJ.h"

using namespace std;

void testCase01() {
    unsigned horse_num = 5;
    unsigned int speed_yanzi[] = {2, 3, 3, 4, 5};
    unsigned int speed_opp[] = {1, 2, 3, 4, 5};
    char* aResult = IsYuanziWin(horse_num, speed_yanzi, speed_opp);

    cout << aResult << " " << "YES"  << endl;;
}

void testCase02() {
    unsigned horse_num = 4;
    unsigned int speed_yanzi[] = {2, 2, 1, 2};
    unsigned int speed_opp[] = {2, 2, 3, 1};
    char * aResult = IsYuanziWin(horse_num, speed_yanzi, speed_opp);

    cout << aResult << " " << "NO"  << endl;;


}

int main() {
    cout << "Hello world!" << endl;
    testCase01();
    testCase02();
    return 0;
}
