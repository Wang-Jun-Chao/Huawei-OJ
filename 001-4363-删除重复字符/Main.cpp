#include <iostream>
#include "OJ.cpp"

using namespace std;

int main(){
    cout << "Hello world!" << endl;
    char* input = "AA BB dd ccc";
    char* output;
    GetResult(input, output);
    cout << input << endl;
    cout << output << endl;

    int rs = GetResult(NULL, NULL);
    cout << rs << endl;

    return 0;
}
