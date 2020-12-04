//
// Created by tck88 on 2020/12/2.
//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void array1() {
    int vector[5];
    printf("数组大小:%lu\n", sizeof(vector) / sizeof(int));
}

void array2() {
    int matrix[2][3] = {{1, 2, 3},
                        {4, 5, 6}};
    for (int i = 0; i < 2; ++i) {
        printf("&matrix[%d]:%p sizeof(matrix[%d]):%lu\n", i, &matrix[i], i, sizeof(matrix[i]));
    }
}

void array3() {
    int matrix[3][2][4] = {
            {{1, 2,  3,  4},  {5,  6,  7,  8}},
            {{9, 10, 11, 12}, {13, 14, 15, 16}},
            {{9, 10, 11, 12}, {9,  10, 11, 12}},
    };
}


void array4() {
    int vector[5];
    int *pv = vector;
    printf("%p\n", vector);
    printf("%p\n", &vector[0]);
    printf("%p\n", pv);
}

void creatArrayByMalloc() {
    int size = 5;

    int *pv = (int *) malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        pv[i] = i + 1;
    }

    printf("creatArray: ");

    for (int i = 0; i < size; ++i) {
        printf("%d ", *(pv + i));
    }

    printf("\n");

}

char *trim(char *phrase) {
    char *old = phrase;
    char *new = phrase;
    printf("%p ", old);
    printf("%p", new);
    while (*old == ' ') {
        old++;
    }
    while (*old) {
        *(new++) = *(old++);
    }
    *new = 0;

    return (char *) realloc(phrase, strlen(phrase) + 1);
}

void creatArrayByRealloc() {
    char *buffer = (char *) malloc(strlen(" cat") + 1);
    strcpy(buffer, " cat");
    printf("%s\n", trim(buffer));
}

//用数组表示法

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void test2() {
    int vector[5] = {1, 2, 3, 4, 5};
    displayArray(vector, 5);

    printf("%lu\n", sizeof(vector));
}

//用指针表示法
void displayArray2(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        printf("*(arr + %d)=%d ", i, *(arr + i));
        printf("arr[%d]=%d", i, arr[i]);
        printf("\n");
    }
}

void test3() {
    int vector[5] = {1, 2, 3, 4, 5};
    displayArray2(vector, 5);
}


void array7() {
    int *arr[5];
    for (int i = 0; i < 5; ++i) {
        arr[i] = (int *) malloc(sizeof(int));
        *arr[i] = i;
    }
    printf("使用指针数组\n");

    for (int i = 0; i < 5; ++i) {
        printf("%d ", *arr[i]);
    }
    printf("\n");
}

void array8() {
    int *arr[5];
    for (int i = 0; i < 5; ++i) {
        arr[i] = (int *) malloc(sizeof(int));
        **(arr + i) = i;
    }
    printf("使用指针数组2\n");

    for (int i = 0; i < 5; ++i) {
        printf("%d ", **(arr+i));
    }
    printf("\n");
}

//int main() {
//    array1();
//    array2();
//    array3();
//    array4();
//    creatArrayByMalloc();
//    creatArrayByRealloc();
//    test2();
//    test3();
//
//    array7();
//    array8();
//    return 0;
//}
