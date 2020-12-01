//
// Created by tck88 on 2020/12/1.
//

#include "stdio.h"

int (*fptr1)(int);

int squared(int num) {
    return num * num;
}


typedef int (*funcptr)(int);


//传递函数指针
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

typedef int (*fptrOperation)(int, int);

int compute(fptrOperation operation, int a, int b) {
    return operation(a, b);
}

//返回函数指针

fptrOperation select(char opcode) {
    switch (opcode) {
        case '+':
            return add;
        case '-':
            return subtract;
        default:
            return NULL;
    }
}

int evaluate(char opcode, int a, int b) {
    fptrOperation operation = select(opcode);
    if (operation == NULL) {
        return 0;
    }
    return operation(a, b);
}

//使用函数指针数组

int (*operations1[128])(int, int) ={NULL};

typedef int (*operation)(int, int);

operation operations[128] = {NULL};

void initialOperationsArray() {
    operations['+'] = add;
    operations['-'] = subtract;
}

int evaluateArray(char opcode, int a, int b) {
    fptrOperation operation = operations[opcode];
    if (operation != NULL) {
        return operation(a, b);
    }
    return 0;
}

//比较函数指针


int main() {
    int n = 5;
    fptr1 = squared;
    printf("%d squared is %d\n", n, fptr1(5));

    funcptr fptr2;
    fptr2 = squared;

    printf("%d squared is %d\n", n, fptr2(5));

    int a = 5;
    int b = 3;

    printf("compute add result             %d\n", compute(add, a, b));
    printf("compute subtract result        %d\n", compute(subtract, a, b));


    printf("evaluate + result              %d\n", evaluate('+', a, b));
    printf("evaluate - result              %d\n", evaluate('-', a, b));

    initialOperationsArray();

    printf("evaluateArray + result         %d\n", evaluateArray('+', a, b));
    printf("evaluateArray - result         %d\n", evaluateArray('-', a, b));


    return 0;
}