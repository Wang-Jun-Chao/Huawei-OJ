
#include "OJ.h"

/*
功能: 根据里程计算车速
原型：
    int CalcSpeedOfCar(int iCurrentMileage, int * piCarSpeed);

输入参数：
    int pcCurrentMileage:当前里程数(为对称数)(pcCurrentMileage ≤ 999999)

返回值：
    汽车速度(公里/小时)
*/

int IsSymmetricNumber(unsigned int speed) {
    unsigned int v = speed;
    unsigned int t = 0;
    while(v != 0) {
        t = t*10 + v%10;
        v /= 10;
    }

    if(speed == t) {
        return 1;
    } else {
        return 0;
    }
}

int CalcSpeedOfCar(int iCurrentMileage, int * piCarSpeed) {

    if(iCurrentMileage < 1 || iCurrentMileage > 999999) {
        return 1;
    }

    unsigned int v = iCurrentMileage + 1;

    while(v <= 999999) {
        if(IsSymmetricNumber(v)) {
            break;
        }

        v++;
    }

    if(v > 999999) {
        *piCarSpeed = 0;
        return 1;
    }

    *piCarSpeed = (v - iCurrentMileage) / 2;

    return 0;
}
