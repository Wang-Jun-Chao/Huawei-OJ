#include <iostream>
#include "OJ.h"

using namespace std;

void testCase01() {
    char result[128] = {0};
    BiNode dataa = {'a', NULL, NULL};
    BiNode datab = {'b', NULL, NULL};
    BiNode datac = {'c', NULL, NULL};
    BiNode datad = {'d', NULL, NULL};
    BiNode datae = {'e', NULL, NULL};
    BiNode dataf = {'f', NULL, NULL};
    BiNode datag = {'g', NULL, NULL};
    BiNode datah = {'h', NULL, NULL};
    BiNode datai = {'i', NULL, NULL};
    BiNode dataj = {'j', NULL, NULL};
    BiNode datak = {'k', NULL, NULL};
    BiNode datal = {'l', NULL, NULL};
    BiNode datam = {'m', NULL, NULL};
    BiNode datan = {'n', NULL, NULL};
    BiNode datao = {'o', NULL, NULL};
    BiNode datap = {'p', NULL, NULL};

    dataa.left = &datab;
    dataa.right = &datac;
    datab.left = &datad;
    datab.right = &datae;
    datac.left = &dataf;
    datac.right = &datag;
    datad.left = &datah;
    datad.right = &datai;
    datae.left = &dataj;
    datae.right = &datak;
    dataf.left = &datal;
    dataf.right = &datam;
    datag.left = &datan;
    datag.right = &datao;
    datah.left = &datap;

    unsigned int ulWidth = 0;
    unsigned int ulHeight = 0;
    cout << GetBiNodeInfo(dataa, &ulWidth, &ulHeight) << " " << 0 << endl;
    cout << ulWidth << " " <<  8 << endl;
    cout << ulHeight << " " << 5 << endl;
}


int main() {
    cout << "Hello world!" << endl;

    testCase01();

    return 0;
}
