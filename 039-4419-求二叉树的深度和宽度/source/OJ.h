#ifndef __OJ_H__
#define __OJ_H__


typedef struct tagBiNode {
    char             data;
    struct tagBiNode *left;
    struct tagBiNode *right;
} BiNode;

int GetBiNodeInfo(BiNode &head, unsigned int *pulWidth, unsigned int *pulHeight);

#endif
