/******************************************************************************

Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

******************************************************************************
File Name     :
Version       :
Author        :
Created       : 2010/3
Last Modified :
Description   :
Function List :

History       :
1.Date        : 2010/3
Author      :
Modification: Created file

******************************************************************************/
#include <cstdio>
#include <queue>
#include <cstring>
#include <map>

using namespace std;

// 定义一个函数对象
typedef void (* PROC_FUN)(void);

// 定义一个结点结构体
typedef struct Node {
    int swiId;      // 软件中断ID
    int prio;       // 软中断优先级
    PROC_FUN proc;  // 软件中断执行函数对象

    // 函数比较器对象
    friend bool operator < (Node n1, Node n2) {
        return n1.prio > n2.prio;
    }
} SwitchNode;

// 全局优先队列，按照prio从小到大排列
priority_queue<SwitchNode> globleSwiQueue;
// 全局软件中断映射
map<int, SwitchNode> globleSwiMap;
// 运行的ID
int runningId;

/*************************************************************************************************
函数说明：创建软中断
输入参数：
      swiId： 创建软中断ID；
	  prio：  创建软中断优先级；
      proc：  创建软中断处理函数。
输出参数：无
返回值  ：成功返回0， 其它情况返回-1
**************************************************************************************************/
int SwiCreate(unsigned int swiId, unsigned int prio, void (* proc)(void)) {

    // 判断是输入参数是否合法
    if(prio < 0 || prio > 31 || proc == NULL || globleSwiMap.count(swiId) != 0) {
        return -1;
    } else {
        // 创建结点对象
        SwitchNode node;
        node.swiId = swiId;
        node.prio = prio;
        node.proc = proc;
        globleSwiMap[swiId] = node;
    }

    return 0;
}

/*************************************************************************************************
函数说明：软中断激活
输入参数：swiId： 待激活软中断ID
输出参数：无
返回值  ：成功返回0， 其它情况返回-1
**************************************************************************************************/
int SwiActivate(unsigned int swiId) {

    // 没有对应的软中断Id
    if(globleSwiMap.count(swiId) == 0) {
        return -1;
    }

    // 有对应的软中断ID，软中断对象入队
    globleSwiQueue.push(globleSwiMap[swiId]);

    // 激活比swiId在的软件中断
    while(!globleSwiQueue.empty()) {
        SwitchNode node = globleSwiQueue.top();
        if(runningId != node.swiId) {
            int oldRunningId = runningId;
            runningId = node.swiId;
            node.proc();
            runningId = oldRunningId;
            globleSwiQueue.pop();
        } else {
            break;
        }
    }

    return 0;
}

/*************************************************************************************************
函数说明：清空所有的信息
输入参数：无
输出参数：无
返回值  ：无
**************************************************************************************************/
void Clear(void) {
    runningId = -1;
    globleSwiMap.clear();
    while(!globleSwiQueue.empty()) {
        globleSwiQueue.pop();
    }
}
