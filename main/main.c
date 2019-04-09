#include <stdio.h>

void test();

int main(void){
    int a = 10;
    printf("Hello world!\n");
    test();
    return 0;
}

void test() {
    printf("Hello world2!");
}

