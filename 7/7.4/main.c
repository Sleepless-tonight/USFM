//
// Created by shiliang on 2020-03-05.
//
//


#include <stdio.h>

int main(void) {
    char multiple[] = "My string";

    char *p = &multiple[0];
    printf("The address of the first array element : %p\n", p);
    p = multiple;
    printf("The address obtained from the array name: %p\n", multiple);
    return 0;
    /**
     * 可以从这个程序的输出中得到一个结论: &multiple[0]会产生和multiple表达式相同的值。
     * 这正是我们期望的,因为 multiple 等于数组第一个字节的地址, &multple[0]等于数组第
     * 一个元素的第一个字节,如果它们不同,才令人惊讶。
     */
}