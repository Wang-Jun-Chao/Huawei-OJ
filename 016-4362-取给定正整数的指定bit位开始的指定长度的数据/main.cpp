#include <iostream>
#include<bitset>
#include "OJ.h"

using namespace std;



int main() {

    unsigned int a = 0B11111111000000001111111100000000;
    bitset<32> bs(a);
    cout << bs << endl;

    unsigned int b = GetBitsValue(0B11111111000000001111111100000000, 8, 16);
    bitset<32> bb(b);
    cout << bb << endl;

    unsigned int c = GetBitsValue(0B11111111000000001111111100000000, 8, 1);
    bitset<32> bc(c);
    cout << bc << endl;

    unsigned int d = GetBitsValue(0B11111111000000001111111100000000, 24, 5);
    bitset<32> bd(d);
    cout << bd << endl;

    unsigned int e = GetBitsValue(0B100, 2, 1);
    bitset<32> be(e);
    cout << be << endl;

    return 0;
}
