//
// Created by shiliang on 2020-03-05.
//
//


#include <stdio.h>

int main(void) {
    long value = 9999L;
    long const *pvalue = &value;
    // *pvalue = 8888L;             // 只读变量不可赋值
    value = 7777L;                  // pvalue 指向的值不能改变,但可以对 value 进行任意操作。
    long number = 8888L;
    pvalue = &number;               // 指针本身不是常量

    /*
     * 指向常量的指针
     * 可以改变指针中存储的地址,但不允许使用指针改变它指向的值
     * */

    return 0;
}
