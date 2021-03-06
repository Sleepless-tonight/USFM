//
// Created by shiliang on 2020-03-05.
//
//


#include <stdio.h>
int main(void) {
    long long int number = 0;
    // pnumber 变量是个指针变量
    long long int *pnumber = NULL;
    number = 10;
//    printf("number's address: %p\n", &number);
//    printf("number's value: %d\n\n", number);

    pnumber = &number;
    // pnumber 变量的地址
    printf("pnumber 变量的地址: %p\n", (void *) &pnumber);
    // pnumber 变量的大小
    printf("pnumber 变量的大小: %zd bytes\n", sizeof(pnumber));
    // pnumber 变量存储的值（另一个变量 number 的地址）
    printf("pnumber 变量存储的值: %p\n", pnumber);
    // 通过 取消引用运算符 获得 pnumber 变量存储的地址的变量的值
    printf("pnumber 变量存储的地址的变量的值: %d\n", *pnumber);

    printf("pnumber - 1:%p\n", pnumber - 1);
    printf("pnumber    :%p\n", pnumber);
    printf("pnumber + 1:%p\n", pnumber + 1);

    return 0;
}
