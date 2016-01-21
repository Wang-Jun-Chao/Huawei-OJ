#include <iostream>
#include "OJ.h"

using namespace std;

int main() {

    int arr[] = {1, 1, 2, 3, 4, 5, 6 ,7, 8 ,9, 10, 10};
    int maxValue = NULL;
    int maxNum = NULL;
    int minValue = NULL;
    int minNum = NULL;

    OutputMaxAndMin(arr, 12, &maxValue, &maxNum, &minValue, &minNum);
    cout << maxValue << " " << maxNum << " " << minValue << " " << minNum << endl;

    int arr2[] = {1, 2, 3, 4};
    OutputMaxAndMin(arr2, 4, &maxValue, &maxNum, &minValue, &minNum);
    cout << maxValue << " " << maxNum << " " << minValue << " " << minNum << endl;
    return 0;
}
