#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "OJ.h"

using namespace std;

void printList2(strNode * head) {

    if(head != NULL) {
        strNode * p = head;

        while(p != NULL) {
            cout << p->data << " ";
            p = p->pstrNext;
        }

        cout << endl;
    }
}


strNode *vCreatChan(int * piData, int iNum) {
    int       iLoop         = 0;
    strNode * pstrChanHead  = NULL;
    strNode * pstrChanEnd   = NULL;
    strNode * pstTemp       = NULL;

    if ((NULL == piData) || (iNum < 1)) {
        return NULL;
    }

    pstrChanHead = (strNode *)malloc(sizeof(strNode));
    pstrChanHead->data     = *piData;
    pstrChanHead->pstrNext = NULL;

    pstrChanEnd = pstrChanHead;

    for (iLoop = 1; iLoop < iNum; iLoop++) {
        pstTemp = (strNode *)malloc(sizeof(strNode));
        pstTemp->data = piData[iLoop];
        pstTemp->pstrNext = NULL;

        pstrChanEnd->pstrNext = pstTemp;
        pstrChanEnd = pstrChanEnd->pstrNext;
    }

    return pstrChanHead;
}

int iChanToArray(strNode *pstrChan, int * piData, int * piLenth) {
    int      iLoop    = 0;
    strNode *pstrTemp = pstrChan;

    if ((NULL == pstrChan) || (NULL == piData) || (NULL == piLenth)) {
        return -1;
    }

    while(NULL != pstrTemp) {
        *(piData + iLoop) = pstrTemp->data;
        pstrTemp = pstrTemp->pstrNext;
        iLoop++;
    }

    *piLenth = iLoop;

    return 0;
}

void testCase01() {
    /* TODO: 请测试时改变改用例 */
    strNode * pstrIn  = NULL;
    strNode * pstrOut = NULL;
    int  iLenth  = 0;
    int  iaDataIn[7]    = {6, 7, 8, 8,9, 10, 6};
    int  iaDataOut[7]   = {10,9,7};
    int  iaDataMyOut[7] = {0};

    pstrIn = vCreatChan(iaDataIn, 7);

    printList2(pstrIn);



    pstrOut = (strNode *)malloc(sizeof(strNode));
    pstrOut->pstrNext = NULL;

    //调用被测函数
    //请考生自己构造单向链表进行测试
    iChanProcess(pstrIn,pstrOut);

    printList2(pstrIn);
    printList2(pstrOut);

    // TODO: 执行完成后可比较是否是你认为正确的值
    iChanToArray(pstrOut, iaDataMyOut, &iLenth);
    //printf("%d\n",pstrOut->data);

    cout << "==========================" << endl;
    for(int i = 0; i < iLenth; i++) {
        cout << iaDataMyOut[i] << " ";
    }

    cout << endl;

    for(int i = 0; i < iLenth; i++) {
        cout << iaDataOut[i] << " ";
    }
    cout << endl;
    cout << "==========================" << endl;
    cout << 3 << " " << iLenth << endl;
    cout << 0 << " " <<  memcmp((char *)iaDataOut, (char *)iaDataMyOut, sizeof(int) * iLenth) << endl;

    //释放内存
    vFreeChan(pstrIn);
    vFreeChan(pstrOut);

}

int main() {
    cout << "Hello world!" << endl;

    testCase01();
    return 0;
}
