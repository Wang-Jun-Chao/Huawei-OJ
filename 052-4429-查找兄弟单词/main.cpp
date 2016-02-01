#include <iostream>
#include <string.h>

#include "FindSimilarWord.h"

using namespace std;
char *Test_Word[8] = {
    "mock",
    "aabc",
    "abc",
    "ckom",
    "bcaa",
    "abca",
    "abca",
    "abcaaaa",
};

int main() {
    cout << "Hello world!" << endl;

    int rst = 0;
    rst = AddOneWord(Test_Word[0]);
    cout << rst << endl;
    rst = AddOneWord(Test_Word[1]);
    cout << rst << endl;
    rst = AddOneWord(Test_Word[2]);
    cout << rst << endl;
    rst = AddOneWord(Test_Word[3]);
    cout << rst << endl;
    rst = AddOneWord(Test_Word[4]);
    cout << rst << endl;
    rst = AddOneWord(Test_Word[5]);
    cout << rst << endl;
    rst = AddOneWord(Test_Word[6]);
    cout << rst << endl;
     rst = AddOneWord(Test_Word[7]);
    cout << rst << endl << endl;

    //printDic();

    int Expectnumber = 1;
    int ActualNumber;
    int Ret;

    ActualNumber = FindSimilarWordNum (Test_Word[0]);
    cout << Expectnumber << " " << ActualNumber << endl;

    char *ExpectWord = {"bcaa"};
    char SimilarWord[51] = {'\0'};
    int Seq = 2;
    Ret = FindOneSimilarWord (Test_Word[1], Seq, SimilarWord);

    cout << 0 << " " << Ret << endl;
    cout << ExpectWord << "=" << SimilarWord << endl;
    cout << (!memcmp(ExpectWord, SimilarWord, strlen(ExpectWord) + 1)) << endl;

    return 0;
}

