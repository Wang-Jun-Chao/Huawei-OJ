#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<string.h>
#define MaxNum 30010
using namespace std;
int num[MaxNum];
int max(int a, int b) {
    return a > b ? a : b;
}
struct SegmentreeNodeTree {
    int left;
    int right;
    int num;
    int calmid() {
        return (left + right) / 2;
    }
} treeNode[3 * MaxNum];

int build(int left, int right, int idx) {
    treeNode[idx].left = left;
    treeNode[idx].right = right;
    treeNode[idx].num = -1;
    if (left == right)
        return treeNode[idx].num = num[left];
    int mid = (left + right) / 2;
    return treeNode[idx].num = max(build(left, mid, idx << 1),build(mid + 1, right, (idx << 1) + 1));
}

void update(int id, int x, int idx) {
    if (treeNode[idx].left == treeNode[idx].right) {
        treeNode[idx].num = x;
        return;
    }
    int mid = (treeNode[idx].left + treeNode[idx].right) / 2;
    if (id <= mid)
        update(id, x, idx << 1);
    else
        update(id, x, (idx << 1) + 1);
    treeNode[idx].num = max(treeNode[idx << 1].num, treeNode[(idx << 1) + 1].num);
}

int Query(int left, int right, int idx) {
    if (left == treeNode[idx].left&&right == treeNode[idx].right)
        return treeNode[idx].num;
    int mid = (treeNode[idx].left + treeNode[idx].right) / 2;
    if (right <= mid)
        return Query(left, right, idx << 1);
    else if (left > mid)
        return Query(left, right, idx << 1 | 1);
    else
        return max(Query(left, mid, idx << 1), Query(mid + 1, right, idx << 1 | 1));
}

int main() {
    //freopen("data.txt", "r", stdin);
    int stuNums, queryNums;
    while (cin >> stuNums >> queryNums) {
        for (int i = 1; i <= stuNums; i++)
            cin >> num[i];
        build(1, stuNums, 1);
        while (queryNums--) {
            char type;
            int num1, num2;
            cin >> type;
            cin >> num1 >> num2;
            if (num2 < stuNums) num2 += 1;
            if (num1 < stuNums) num1 += 1;
            switch (type) {
            case 'Q':
                printf("%d\n", Query(num1, num2, 1));
                break;
            case 'U':
                update(num1, num2, 1);
                break;
            }
        }
    }
    return 0;
}
