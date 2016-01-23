
#include "OJ.h"
#include <string.h>
#include <stdio.h>
#include <list>
#include <iostream>
using namespace std;

/*
Description
         给定一个二叉树，获取该二叉树的宽度深度。
Prototype
         int GetBiNodeInfo(BiNode &head, unsigned int *pulWidth, unsigned int *pulHeight)
Input Param
         head   需要获取深度的二叉树头结点
Output Param
         pulWidth   宽度
         pulHeight  高度
Return Value
         0          成功
         1          失败或其他异常
*/
int GetBiNodeInfo(BiNode &head, unsigned int *pulWidth, unsigned int *pulHeight) {

    if(&head == NULL || pulWidth == NULL || pulHeight == NULL) {
        return 1;
    }

    *pulWidth = 0;
    *pulHeight = 0;

    list<BiNode *> currLevel;
    list<BiNode *> nextLevel;

    currLevel.push_back(&head);
    (*pulHeight)++;
    *pulWidth = currLevel.size();

    while(!currLevel.empty()) {
        list<BiNode *>::iterator itr = currLevel.begin();
        if((*itr)->left != NULL) {
            nextLevel.push_back((*itr)->left);
        }

        if((*itr)->right != NULL) {
            nextLevel.push_back((*itr)->right);
        }

        currLevel.erase(itr);

        if(currLevel.empty()) {

            currLevel.swap(nextLevel);
            // 有数代处理
            if (!currLevel.empty()) {
                // 高度增加
                (*pulHeight)++;

                // 更新宽度
                if (*pulWidth < currLevel.size()) {
                    *pulWidth = currLevel.size();
                }
            }
        }
    }

    return 0;
}
