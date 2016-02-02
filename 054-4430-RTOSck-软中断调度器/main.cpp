#include <iostream>
#include <stdlib.h>
#include <string.h>


using namespace std;

extern int SwiCreate(unsigned int swiId, unsigned int prio, void (* proc)(void));
extern int SwiActivate(unsigned int swiId);
extern void Clear();

static unsigned int * schedTrace;
static unsigned int   schedTraceCnt;
static unsigned int   schedTraceSize;

void SchedTraceInit(unsigned int * p, unsigned int size) {
    schedTrace = p;
    schedTraceCnt = 0;
    schedTraceSize = size;
}

void SchedTraceRecord(unsigned int pid) {
    if (schedTraceCnt < schedTraceSize)
        schedTrace[schedTraceCnt++] = pid;
}

static void TestCase01_proc1() {
    SchedTraceRecord(1);
    SwiActivate(2);
    SchedTraceRecord(1);
}

static void TestCase01_proc2() {
    SchedTraceRecord(2);
    SwiActivate(3);
    SchedTraceRecord(2);
}
static void TestCase01_proc3() {
    SchedTraceRecord(3);
}


void testCase01() {
    int ret;
    unsigned int trace[10];
    unsigned int expect[] = {1, 2, 2, 3, 1};

    SchedTraceInit(trace, 10);
    Clear();

    ret = SwiCreate(1, 5, TestCase01_proc1);
    cout << (0 == ret) << endl;

    ret = SwiCreate(2, 3, TestCase01_proc2);
    cout << (0 == ret) << endl;

    ret = SwiCreate(3, 4, TestCase01_proc3);
    cout << (0 == ret) << endl;

    ret = SwiActivate(1);
    cout << (0 == ret)<< endl;

    cout << (5 == schedTraceCnt)<< endl;
    cout << (0 == memcmp(expect, trace, sizeof(expect)))<< endl;
}

int main() {
    cout << "Hello world!" << endl;

    testCase01();

    return 0;
}
