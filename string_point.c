//
// Created by tck88 on 2020/12/4.
//

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//错误
void string_test() {
    char *tabHeader = "Sound";
    *tabHeader = 'L';

    printf("%s\n", tabHeader);
}

void string_test2() {
    char headr[] = "hello c";

    char headr2[13];

    strcpy(headr2, "hello c");

}

//初始化指针
void string_test3() {
    char *header = (char *) malloc(strlen("hello c") + 1);
    strcpy(header, "hello c");

    printf("sizeof %s ,length= %lu\n", "hello c", sizeof(header));
    printf("strlen %s ,length= %lu\n", "hello c", strlen("hello c"));

}

//错误
void string_test4() {
    char *prefix = '+';
    printf("%c", *prefix);
}

void string_test5() {
    char *prefix = (char *) malloc(2);
    *prefix = '+';
    *(prefix + 1) = 0;
    printf("%c\n", *prefix);
}

//字符串比较
void string_test6() {
    //=0
    printf("tck strcmp tck %d\n", strcmp("tck", "tck"));
    //>1
    printf("tck1 strcmp tck %d\n", strcmp("tck1", "tck"));
    //< -1
    printf("tck strcmp tck1 %d\n", strcmp("tck", "tck1"));
}

//复制字符串
void string_test7() {
    //strcpy
}

//拼接字符串
void string_test8() {
    char *hello = "hello";
    char *c = "C";
    char *buffer = (char *) malloc(strlen(hello) + strlen(c) + 1);
    strcpy(buffer,hello);
    strcat(buffer,c);
    printf("%s\n",hello);
    printf("%s\n",c);
    printf("%s\n",buffer);
}

int main() {
    // string_test();
    string_test2();
    string_test3();
    // string_test4();
    string_test5();
    string_test6();
    string_test7();
    string_test8();
    return 0;
}