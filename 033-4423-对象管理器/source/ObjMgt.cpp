#include "ObjMgt.h"
#include <map>
#include <vector>

using namespace std;

map<long long, bool> ObjManager;

/*************************************************************************
功能：增加单个对象
输入：
key1  外部关键字 KEY1
key2  外部关键字KEY2
key3  外部关键字KEY3
输出：无
返回：
      -1 :失败(对象已经存在或者其它异常)
       0 :成功
***************************************************************************/
int AddObject (unsigned int key1, unsigned int key2, unsigned int key3) {

    long long llk1 = (long long)key1;
    long long llk2 = (long long)key2;
    long long llk3 = (long long)key3;
    llk1 <<= 32;
    llk2 <<= 16;
    long long key=llk1 + llk2 + llk3;
    if(!ObjManager.count(key)) {
        ObjManager[key] = true;
    } else  {
        return -1;
    }

    return 0;
}

/********************************************************************************
功能：删除一个或多个对象
输入：
      key1 外部关键字 KEY1
      key2 外部关键字 KEY2
      key3 外部关键字 KEY3
输出：无
返回：无

说明：用例保证参数取值为合法值和通配符0xFFFFFFFF, 通配符表示0~65535范围内的任意值;
      举例:key1=1,key2=2,key3= 0xFFFFFFFF，表示删除key1=1,key2=2的所有对象;
           key1,key2,key3取值全为0xFFFFFFFF时,表示删除所有对象。
*********************************************************************************/
void DeleteObject (unsigned int key1, unsigned int key2, unsigned int key3) {
    map<long long, bool>::iterator it;
    unsigned int myKey1, myKey2, myKey3;
    vector<long long> keyShouldRrase;
    for(it = ObjManager.begin(); it != ObjManager.end(); it++) {
        long long key = (*it).first;
        myKey1= (key & 0xFFFF00000000) >> 32;
        myKey2 = (key & 0xFFFF0000) >> 16;
        myKey3 = key & 0xFFFF;
        if((0xFFFFFFFF == key1 || myKey1 == key1)
                && (0xFFFFFFFF == key2 || myKey2 == key2)
                && (0xFFFFFFFF == key3 || myKey3 == key3)) {
            keyShouldRrase.push_back(key);
        }
    }
    for(int i=0; i< keyShouldRrase.size(); i++) {
        ObjManager.erase(keyShouldRrase[i]);
    }

    return ;
}

/********************************************************************************
功能：查询单个对象是否存在
输入：
      key1 外部关键字 KEY1
      key2 外部关键字 KEY2
      key3 外部关键字 KEY3
输出：无
返回：
      0：不存在
      1：存在
**********************************************************************************/
int IsObjectExist (unsigned int key1, unsigned int key2, unsigned int key3) {
    long long llk1 = (long long)key1;
    long long llk2 = (long long)key2;
    long long llk3 = (long long)key3;
    llk1 <<= 32;
    llk2 <<= 16;
    long long key=llk1 + llk2 + llk3;
    if(ObjManager.count(key)) {
        return 1;
    }

    return 0;
}

/******************************************************************************************************
Description     清空所有对象
Prototype       void Clear();
Input Param     无
Output Param    无
Return Value    无

********************************************************************************************************/
void Clear(void) {
    ObjManager.clear();
    return;
}
