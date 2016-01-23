#include <stdlib.h>
#include <iostream>

#include "oj.h"

using namespace std;
/*
功能: 矩阵相乘

输入: MatrixA,MatrixB

输出: MatrixC

返回: 0

*/

int matrix(int **MatrixA, int **MatrixB, int **MatrixC, int N) {

    if(MatrixA == NULL || MatrixB == NULL || MatrixC == NULL || N < 1) {
        return 1;
    }

    int * arr = (int *) MatrixA;
    int * brr = (int *) MatrixB;
    int * crr = (int *) MatrixC;

    cout << "=====" << endl;
/*
    for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
               // cout << (*(*(MatrixA + i) + j)) << " ";
                cout << (*(*MatrixA+i*N+j)) << " ";
            }

    }
*/
/*
for(int i = 0; i < N*N; i++) {
    cout <<(int) *(MatrixA + i) << " ";

}
    cout << endl;
*/



        for(int row = 0; row < N; row++) {
            for(int col = 0; col <N; col++) {
                int sum = 0;

                for(int i = 0; i < N; i++) {
                    sum += ((arr[row * N + i])) * ((brr[i * N + col]));
                }

               (crr[row * N + col]) = sum;

            }
        }

    return 0;
}
