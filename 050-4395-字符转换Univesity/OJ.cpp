#include <stdlib.h>
#include "oj.h"

#include <iostream>

using namespace std;


char* CharReplace(char* pSourceChar) {

    if(pSourceChar == NULL) {
        return NULL;
    }

    int len = 0;
    while(pSourceChar[len] != '\0') {
        len++;
    }

    char* pResultChar = (char *)malloc(sizeof(char)*(len + 1));

    char upperMask[] = {'E', 'C', 'F', 'A', 'J', 'K', 'L', 'B', 'D', 'G', 'H', 'I', 'V', 'W', 'Z', 'Y', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'X'};
    char lowerMask[] = {'e', 'r', 'w', 'q', 't', 'y', 'g', 'h', 'b', 'n', 'u', 'i', 'o', 'p', 's', 'j', 'k', 'd', 'l', 'f', 'a', 'z', 'x', 'c', 'v', 'm'};


    len = 0;
    while(pSourceChar[len] != '\0') {

        if(pSourceChar[len] >= 'A' && pSourceChar[len] <= 'Z') {
            pResultChar[len] = upperMask[pSourceChar[len] - 'A'];
        } else if(pSourceChar[len] >= 'a' && pSourceChar[len] <= 'z') {
            pResultChar[len] = lowerMask[pSourceChar[len] - 'a'];
        } else {
            pResultChar[len] = pSourceChar[len];
        }

        len++;
    }

    pResultChar[len] = '\0';

    return pResultChar;
}
