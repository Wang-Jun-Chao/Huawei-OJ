/******************************************************************************

  Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     :
  Version       :
  Author        :
  Created       : 2012/03/12
  Last Modified :
  Description   :
  Function List :

  History       :
  1.Date        : 2012/03/12
    Author      :
    Modification: Created file

******************************************************************************/
#include <iostream>
#include <stdlib.h>

#define MAXSIZE 50


using namespace std;


struct strqueue {
    int queue[MAXSIZE];
    int head; /* 队头 */
    int tail; /* 队尾 */
    int num;  /* 队元素个数 */
};

bool initqueue(struct strqueue *s) { /* 初始化队列，返回0表示失败，返回1表示成功 */

    if(s == NULL) {
        return 0;
    }

    s->head = -1;
    s->tail = -1;
    s->num = 0;

    for(int i = 0; i < MAXSIZE; i++) {
        s->queue[i] = 0;
    }

    return 1;
}

bool enqueue(struct strqueue *s, int x) { /* 进队列，返回0表示失败，返回1表示成功 */

    if(s == NULL) {
        return 0;
    }

    int result = 0;

    if(s->num == 0) {
        s->tail = (s->tail + 1)/MAXSIZE;
        s->queue[s->tail] = x;
        s->head = s->tail;
        s->num++;
        result = 1;
    } else if(s->num == MAXSIZE) {
        result = 0;
    } else {
        s->tail = (s->tail + 1)%MAXSIZE;
        s->queue[s->tail] = x;
        s->num++;
        result = 1;
    }

    return result;
}

bool dequeue(struct strqueue *s, int *x) { /* 出队列，返回0表示失败，返回1表示成功 */

    if(s == NULL || x == NULL) {
        return 0;
    }

    bool result = 0;

    if(s->num == 0) {
        result = 0;
    } else {
        *x = s->queue[s->head];
        s->queue[s->head] = 0;
        s->head = (s->head + 1)%MAXSIZE;
        s->num--;

        if(s->num == 0) {
            s->head =-1;
            s->tail = -1;
        }

        result = 1;
    }


    return result;
}

int gethead(struct strqueue *s) { /* 获得队列头数值 */
    if(s == NULL || s->num == 0) {
        return -1;
    }

    int head = 0;
    head = s->queue[s->head];

    return head;
}


int gettail(struct strqueue *s) { /* 获得队列尾数值 */
    if(s == NULL || s->num == 0) {
        return -1;
    }

    int tail = 0;
    tail = s->queue[s->tail];

    return tail;
}

int getqueuelenth(struct strqueue *s) { /* 获得队列长度 */

    if(s == NULL) {
        return 0;
    }

    int lenth = 0;
    lenth = s->num;

    return lenth;
}

bool search(struct strqueue *s, int x) { /* 在队列中查找x是否存在，如果存在返回1，否则返回0 */

    if(s == NULL || s->num == 0) {
        return 0;
    }

    bool result = 0;

    int p = s->head;
    for(int i = 0; i < s->num; i++) {
        if(s->queue[(p + i)%MAXSIZE] == x) {
            result = 1;
            break;
        }
    }

    return result;
}



/////////////////////////////////////////////////////////////////////////////

void test01() {
    struct strqueue s;
    bool result = 0;
    int i = 0;

    result = initqueue(&s);

    cout << result << " " << (result == 1) << endl;
    for(i = 0; i < MAXSIZE; i++) {
        cout << s.queue[i] << " " << (s.queue[i] == 0) << endl;
    }
    cout << s.head << " " << (s.head == -1) << endl;
    cout << s.tail << " " << (s.tail == -1) << endl;
    cout << s.num << " " << (s.num == 0) << endl;
}
void test02() {
    struct strqueue s;
    bool result = 0;

    result = initqueue(&s);
    result = enqueue(&s, 1);

    cout << (result == 1) << endl;
    cout << (s.queue[0] == 1) << endl;
    cout << (s.head == 0) << endl;
    cout << (s.tail == 0) << endl;
    cout << (s.num == 1) << endl;
}
void test03 () {
    struct strqueue s;
    bool result = 0;

    result = initqueue(&s);
    result = enqueue(&s, 1);
    result = enqueue(&s, 2);

    cout << (result == 1)  << endl;
    cout << (s.queue[0] == 1) << endl;
    cout << (s.queue[1] == 2) << endl;
    cout << (s.head == 0) << endl;
    cout << (s.tail == 1) << endl;
    cout << (s.num == 2) << endl;
}

void test04() {

    struct strqueue s;
    bool result = 0;

    result = initqueue(&s);

    s.queue[15] = 1;
    s.queue[16] = 2;
    s.queue[17] = 3;
    s.queue[18] = 4;
    s.head = 15;
    s.tail = 18;
    s.num = 4;

    result = enqueue(&s, 5);

    cout << (result == 1) << endl;
    cout << (s.queue[15] == 1) << endl;
    cout << (s.queue[16] == 2) << endl;
    cout << (s.queue[17] == 3) << endl;
    cout << (s.queue[18] == 4) << endl;
    cout << (s.queue[19] == 5) << endl;
    cout << (s.head == 15) << endl;
    cout << (s.tail == 19) << endl;
    cout << (s.num == 5) << endl;
}

void test05() {

    struct strqueue s;
    bool result = 0;

    result = initqueue(&s);

    s.queue[46] = 1;
    s.queue[47] = 2;
    s.queue[48] = 3;
    s.queue[49] = 4;
    s.head = 46;
    s.tail = 49;
    s.num = 4;

    result = enqueue(&s, 5);

    cout << (result == 1) << endl;
    cout << (s.queue[46] == 1) << endl;
    cout << (s.queue[47] == 2) << endl;
    cout << (s.queue[48] == 3) << endl;
    cout << (s.queue[49] == 4) << endl;
    cout << (s.queue[0] == 5) << endl;
    cout << (s.head == 46) << endl;
    cout << (s.tail == 0) << endl;
    cout << (s.num == 5) << endl;

}

void test06() {
    struct strqueue s;
    bool result = 0;
    int i = 0;

    result = initqueue(&s);

    for(i = 0; i < MAXSIZE; i++) {
        s.queue[i] = i+1;
    }
    s.head = 0;
    s.tail = 49;
    s.num = 50;

    result = enqueue(&s, 51);

    cout << (result == 0) << endl;
    for(i = 0; i < MAXSIZE; i++)  	{
        cout << (s.queue[i] == (i+1))<< endl;
    }
    cout << (s.head == 0)<< endl;
    cout << (s.tail == 49)<< endl;
    cout << (s.num == 50)<< endl;
}

void test07() {
    struct strqueue s;
    int x = 0;
    bool result = 0;

    result = initqueue(&s);
    result = dequeue(&s, &x);

    cout << (result == 0)<< endl;
    cout << (s.head == -1)<< endl;
    cout << (s.tail == -1)<< endl;
    cout << (s.num == 0)<< endl;

}

void test08() {

    struct strqueue s;
    int x = 0;
    bool result = 0;

    result = initqueue(&s);
    result = enqueue(&s, 1);
    result = dequeue(&s, &x);

    cout << (result == 1)<< endl;
    cout << (x == 1)<< endl;
    cout << (s.queue[0] == 0)<< endl;
    cout << (s.head == -1)<< endl;
    cout << (s.tail == -1)<< endl;
    cout << (s.num == 0) << endl;
}

void test09() {
    struct strqueue s;
    int x = 0;
    bool result = 0;

    result = initqueue(&s);

    s.queue[15] = 1;
    s.queue[16] = 2;
    s.queue[17] = 3;
    s.queue[18] = 4;
    s.head = 15;
    s.tail = 18;
    s.num = 4;

    result = dequeue(&s, &x);

    cout << (result == 1) << endl;
    cout << (x == 1) << endl;
    cout << (s.queue[15] == 0) << endl;
    cout << (s.queue[16] == 2) << endl;
    cout << (s.queue[17] == 3) << endl;
    cout << (s.queue[18] == 4) << endl;
    cout << (s.head == 16) << endl;
    cout << (s.tail == 18) << endl;
    cout << (s.num == 3) << endl;
}

void test10() {

    struct strqueue s;
    int x = 0;
    bool result = 0;

    result = initqueue(&s);

    s.queue[49] = 1;
    s.queue[0] = 2;
    s.queue[1] = 3;
    s.queue[2] = 4;
    s.head = 49;
    s.tail = 2;
    s.num = 4;

    result = dequeue(&s, &x);

    cout << (result == 1) << endl;
    cout << (x == 1) << endl;
    cout << (s.queue[49] == 0) << endl;
    cout << (s.queue[0] == 2) << endl;
    cout << (s.queue[1] == 3) << endl;
    cout << (s.queue[2] == 4) << endl;
    cout << (s.head == 0) << endl;
    cout << (s.tail == 2) << endl;
    cout << (s.num == 3) << endl;
}

void test11() {
    struct strqueue s;
	int x = 0;
	bool result = 0;

	result = initqueue(&s);

	s.queue[15] = 1;
	s.queue[16] = 2;
	s.queue[17] = 3;
	s.queue[18] = 4;
	s.head = 15;
	s.tail = 18;
	s.num = 4;

	x = gethead(&s);

	cout << (x == 1) << endl;
}

void test12() {
    struct strqueue s;
	int x = 0;
	bool result = 0;

	result = initqueue(&s);

	x = gethead(&s);

	cout << (x == -1) << endl;
}

void test13() {
	struct strqueue s;
	int x = 0;
	bool result = 0;

	result = initqueue(&s);

	s.queue[15] = 1;
	s.queue[16] = 2;
	s.queue[17] = 3;
	s.queue[18] = 4;
	s.head = 15;
	s.tail = 18;
	s.num = 4;

	x = gettail(&s);

	cout << (x == 4) << endl;
}
void test14() {
    struct strqueue s;
	int x = 0;
	bool result = 0;

	result = initqueue(&s);

	x = gettail(&s);

	cout << (x == -1) << endl;

}

void test15() {

    struct strqueue s;
	int x = 0;
	bool result = 0;

	result = initqueue(&s);

	s.queue[15] = 1;
	s.queue[16] = 2;
	s.queue[17] = 3;
	s.queue[18] = 4;
	s.head = 15;
	s.tail = 18;
	s.num = 4;

	result = search(&s, 2);

	cout << (result == 1) << endl;

}

void test16() {

	struct strqueue s;
	int x = 0;
	bool result = 0;

	result = initqueue(&s);

	s.queue[15] = 1;
	s.queue[16] = 2;
	s.queue[17] = 3;
	s.queue[18] = 4;
	s.head = 15;
	s.tail = 18;
	s.num = 4;

	result = search(&s, 5);

    cout << (result == 0) << endl;

}

void test17() {

	struct strqueue s;
	int x = 0;
	bool result = 0;

	result = initqueue(&s);

	s.queue[48] = 1;
	s.queue[49] = 2;
	s.queue[0] = 3;
	s.queue[1] = 4;
	s.head = 48;
	s.tail = 1;
	s.num = 4;

	result = search(&s, 2);

	cout << (result == 1) << endl;

}
void test18() {

struct strqueue s;
	int x = 0;
	bool result = 0;

	result = initqueue(&s);

	s.queue[48] = 1;
	s.queue[49] = 2;
	s.queue[0] = 3;
	s.queue[1] = 4;
	s.head = 48;
	s.tail = 1;
	s.num = 4;

	result = search(&s, 3);

	cout << (result == 1) << endl;

}

void test19() {
	struct strqueue s;
	int x = 0;
	bool result = 0;

	result = initqueue(&s);

	s.queue[48] = 1;
	s.queue[49] = 2;
	s.queue[0] = 3;
	s.queue[1] = 4;
	s.head = 48;
	s.tail = 1;
	s.num = 4;

	result = search(&s, 5);

	cout << (result == 0) << endl;
}
int main() {
    cout << "Hello world!" << endl;
    // test01();
    // test02();
    //test03();
    // test04();
    // test05();
    // test06();
    //  test07();
    //test08();
    //test09();
  //  test10();
    //test11();
    //test12();
    //test13();
    //test14();
    //test15();
   // test16();
    //test17();
    //test18();
    test19();
    return 0;
}
