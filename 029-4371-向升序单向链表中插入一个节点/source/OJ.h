#ifndef __OJ_H__
#define __OJ_H__

#ifndef NULL
#define NULL ((void*)0)
#endif

struct ListNode {
    int       m_nKey;
    ListNode* m_pNext;
};

ListNode* InsertNodeToList(ListNode* pListHead, ListNode* pInsertNode);

#endif
