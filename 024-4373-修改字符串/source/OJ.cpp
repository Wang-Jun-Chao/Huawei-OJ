#include <stdlib.h>
#include <string.h>
#include "oj.h"

int ChangeString(char *pInStr,char *pOutStr) {

    if(pInStr == NULL || pOutStr == NULL) {
        return -1;
    }

    char * str = (char *) malloc((strlen(pInStr) + 1)*sizeof(char));

    strcpy(str, pInStr);

    char * p;
    char * q;
    int handle;
    do {
        // 是否有进行字符串处理操作
        handle = 0;

        char * p = str;
        char * q = pOutStr;

        while(*p != '\0') {
            if(*p >= 'a' && *p <= 'z') {

                // 连续三个相同的小写字母，对三个进行替换
                if(*(p + 1) != '\0' && *(p + 2) != '\0' && *p == *(p + 1) && *p == *(p + 2)) {
                    *q = (char)((*p - 'a' + 1)%26 + 'a');
                    p = p + 3;

                    // 进行过字符串处理
                    handle = 1;
                } else {
                    *q = *p;
                    p++;
                }

                q++;
            } else {
                *q = *p;
                p++;
                q++;
            }
        }

        *q = '\0';

        if(handle != 0) {
            strcpy(str, pOutStr);
        }

    }while(handle != 0);


    free(str);

    return 0;
}

// 对连续三个及其以上的字符串进行替换
int ChangeString2(char *pInStr,char *pOutStr) {

    if(pInStr == NULL) {
        return -1;
    }


    char * p = pInStr;
    char * q = pOutStr;

    while(*p != '\0') {
        if(*p >= 'a' && *p <= 'z') {
            char * r = p + 1;
            while(*r != '\0' && *r == *(r - 1)) {
                r++;
            }

            // 有三个以上的小写字母
            if(r - p >= 3) {
                *q = (char)((*p - 'a' + 1)%26 + 'a');
                p = r;
            } else {
                *q = *p;
                p++;
            }

            q++;
        } else {
            *q = *p;
            p++;
            q++;
        }
    }

    *q = '\0';

    return 0;
}
