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
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//1、对输入的字符串进行加解密，并输出。
//
//2加密方法为：
//当内容是英文字母时则用该英文字母的后一个字母替换，同时字母变换大小写,如字母a时则替换为B；字母Z时则替换为a；
//当内容是数字时则把该数字加1，如0替换1，1替换2，9替换0；
//其他字符不做变化。
//
//3、解密方法为加密的逆过程。

int Encrypt (char password[], char result[]) {
    if(password == NULL || result == NULL) {
        return -1;
    }

    int i = 0;
    while(password[i] != '\0') {
        if(password[i] >= '0' && password[i] <= '9') {
            result[i] = (char)((password[i] - '0' + 1 )%10 + '0');
        } else if(password[i] >= 'a' && password[i] <= 'z') {
            result[i] = (char)((password[i] - 'a' + 1 )%26 + 'A');
        }   else if(password[i] >= 'A' && password[i] <= 'Z') {
            result[i] = (char)((password[i] - 'A' + 1 )%26 + 'a');
        } else {
             result[i] = password[i];
        }

        i++;
    }

    result[i] = '\0';

    return 0;
}

int unEncrypt (char result[], char password[]) {

    if(password == NULL || result == NULL) {
        return -1;
    }

    int i = 0;
    while(result[i] != '\0') {
        if(result[i] >= '0' && result[i]<= '9') {
            password[i] = (char)((result[i] - '0' - 1 + 10 )%10 + '0');
        } else if(result[i] >= 'a' && result[i] <= 'z') {
            password[i] = (char)((result[i] - 'a' - 1 + 26 )%26 + 'A');
        }   else if(result[i] >= 'A' && result[i] <= 'Z') {
            password[i] = (char)((result[i] - 'A' - 1 + 26 )%26 + 'a');
        } else {
             password[i] = result[i];
        }

        i++;
    }

    password[i] = '\0';

    return 0;
}




