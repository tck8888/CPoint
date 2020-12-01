//
// Created by tck88 on 2020/11/30.
//
#include "stdio.h"
#include "stdlib.h"

void allocate_spaces(int **arr, int n) {
    int *temp = (int *) malloc(n * sizeof(int));
    if (NULL == temp) {
        return;
    }

    int *pTemp = temp;
    for (int i = 0; i < n; ++i) {
        *pTemp = i + 100;
        pTemp++;
    }

    *arr = temp;
}

void print_array(int *arr, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

}

void test() {
    int *arr = NULL;
    int n = 10;
    allocate_spaces(&arr, n);
    print_array(arr, n);

    if (arr != NULL) {
        free(arr);
        arr = NULL;
    }
}

//int main() {
//    test();
//
//    char *names[] = {"tck", "yys", "rich"};
//    printf("%s\n", *names);
//    printf("%s\n", *(names + 1));
//    printf("%c\n", *(*(names + 1) + 2));
//    printf("%c\n", names[1][2]);
//    return 0;
//}