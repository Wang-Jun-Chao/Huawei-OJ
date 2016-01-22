#include <iostream>
#include "OJ.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    ListNode astListNode[2];
    ListNode stInsertNode;
    ListNode *pListHead;

    astListNode[0].m_nKey = 1;
    astListNode[0].m_pNext = &astListNode[1];

    astListNode[1].m_nKey = 3;
    astListNode[1].m_pNext = NULL;

    stInsertNode.m_nKey = 2;
    stInsertNode.m_pNext = NULL;

    pListHead = InsertNodeToList(astListNode, &stInsertNode);

    cout << 1 << " " << astListNode[0].m_nKey << endl;
    cout << (astListNode[0].m_pNext == &stInsertNode) << endl << endl;

    cout << 2 << " " << stInsertNode.m_nKey  << endl;
    cout << (stInsertNode.m_pNext == &astListNode[1]) << endl << endl;

    cout << 3 << " " << astListNode[1].m_nKey  << endl;
    cout << (astListNode[1].m_pNext == NULL) << endl << endl;
    return 0;
}
