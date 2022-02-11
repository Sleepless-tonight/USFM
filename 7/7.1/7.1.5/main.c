//
// Created by shiliang on 2020-03-05.
//
//


#include <stdio.h>

int main(void) {


    int count = 43;
    int *const pcount = &count; //常量指针

    *pcount = 345;

    int item = 34;
    // pcount = &item;

    /*
     * 常量指针
     * 指针中存储的地址不能改变
     * */

    const long *pvalue = &count;        // 指向常量的指针
    int *const pcount2 = &count;        // 常量指针
    const int *const pitem = &count;    // 指向常量的常量指针
                                        // 所有的信息都固定不变

    return 0;
}
