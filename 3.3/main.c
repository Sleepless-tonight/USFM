//
// Created by shiliang on 2020-03-05.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
int main(void){
    unsigned int original = 0xABC;
    unsigned int result = 0;
    unsigned int mark = 0xF;
    printf("test %x \n", original);
    char s[20];
    itoa(original, s, 2);
    printf("二进制 --> %s\n", s);
}
