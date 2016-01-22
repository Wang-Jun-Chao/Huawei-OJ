
#include "OJ.h"

/*
功能: 输入一个升序单向链表和一个链表节点，向单向链表中按升序插入这个节点。
	  输入为空指针的情况视为异常，另外不考虑节点值相等的情况。

输入: ListNode* pListHead  单向链表
      ListNode* pInsertNode 新插入节点

输出: ListNode* pListHead  单向链表

返回: 正常插入节点返回链表头指针，其它异常返回空指针
*/
ListNode* InsertNodeToList(ListNode* pListHead, ListNode* pInsertNode) {

    if(pListHead == NULL || pInsertNode == NULL) {
        return (ListNode*)NULL;
    }

    // 使用头结点
    ListNode * root = new ListNode();
    root->m_pNext = pListHead;
    ListNode * p = root;

    // 找要插入的元素的前驱
    while(p->m_pNext != NULL && p->m_pNext->m_nKey < pInsertNode->m_nKey) {
        p = p->m_pNext;
    }

    pInsertNode->m_pNext = p->m_pNext;
    p->m_pNext = pInsertNode;

    return root->m_pNext;
}

