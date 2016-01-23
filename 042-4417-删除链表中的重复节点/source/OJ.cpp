#include <stdlib.h>
#include <iostream>
#include <set>
#include "oj.h"

using namespace std;

// 将与head重复的节点删除，只留下第一个
bool isDuplicateNode(strNode * head, int data) {
    if(head == NULL) {
        return false;
    }
    strNode * next = head->pstrNext;


    while(next != NULL) {
        if(next->data == data) {
            return true;
        }

        next = next->pstrNext;
    }

    return false;
}


/*
功能:  输入一个不带头节点的单向链表(链表的节点数小于100),删除链表中内容重复的节点（重复的节点全部删除），剩余的节点逆序倒排。

输入:   pstrIn： 输入一个不带头节点的单向链表

输出:   pstrOut：删除内容重复的节点后，逆序排列的链表(不带头节点,链表第一个节点的内存已经申请)。

返回:

示例:
输入链表的内容依次为 6,7,8,8,9,10,6
则输出链表的内容依次应该是 10,9,7

*/



int iChanProcess(strNode * pstrIn,strNode * pstrOut) {

    if(pstrIn == NULL || pstrOut == NULL) {
        return -1;
    }

    strNode * p = pstrIn;

    set<int> intSet;

    while(p != NULL) {
        // 如果是重复元素
        if(intSet.find(p->data) != intSet.end()) {
            p = p->pstrNext;
            continue;
        }

        bool dup = isDuplicateNode(p, p->data);

        // 如果是重复元素,并且不在重复元素集合中
        if(dup == true) {
            intSet.insert(p->data);
            p = p->pstrNext;
            continue;
        }

        // 创建一个新的结点
        strNode * node = (strNode *)malloc(sizeof(strNode));
        node->data = p->data;

        // 插入到node节点之后
        node->pstrNext = pstrOut->pstrNext;
        pstrOut->pstrNext = node;


        p = p->pstrNext;

    }

    intSet.clear();

    // 第一个结点有后继结点，将后继结点删除，把后续结点值放在第一个结点上
    if(pstrOut->pstrNext != NULL) {
        strNode * next = pstrOut->pstrNext;
        pstrOut->pstrNext = next->pstrNext;
        pstrOut->data = next->data;
        next->pstrNext = NULL;
        free(next);
    }



    return 0;
}

/* 释放链表 */
void vFreeChan(strNode * pstrChan) {

    if(pstrChan == NULL) {
        return ;
    }

    do {
        strNode * prev = pstrChan;
        pstrChan = pstrChan->pstrNext;
        prev->pstrNext = NULL;
        free(prev);

    } while(pstrChan != NULL);

    return;
}
