//
// Created by shili on 2022/4/7.
//
#include "stdio.h"
#include "stdlib.h"

int main(int argc, char *argv[]) {


    printf("Program name: %s\n", argv[0]);
    for (int i = 1; i < argc; ++i)
        printf("Argument %d: %s\n", i, argv[i]);
    return 0;
}

