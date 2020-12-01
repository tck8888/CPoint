#include <stdio.h>
#include <stdlib.h>

void allocateArray(int **arr, int size, int value) {
    *arr = (int *) malloc(size * sizeof(int));
    if (*arr!=NULL){
        for (int i = 0; i < size; ++i) {
            *(*arr+i)=value;
        }
    }
}

//void allocateArray2(int *arr, int size, int value) {
//    *arr = (int *) malloc(size * sizeof(int));
//    if (*arr!=NULL){
//        for (int i = 0; i < size; ++i) {
//            *(*arr+i)=value;
//        }
//    }
//}

//int main() {
//    int *vector=NULL;
//    allocateArray(&vector,5,45);
//    printf("Hello, World! %p \n",vector);
//
////    int *vector2=NULL;
////    allocateArray2(&vector2,5,45);
////    printf("Hello, World! %p \n",vector2);
//
//    return 0;
//}
