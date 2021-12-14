//
// Created by shiliang on 2020-03-05.
//
//
#include <stdio.h>
int main(void){

#ifdef __STDC_NO_VAL__
    printf("not");
    exit(1);
#endif
    size_t size = 0;
//    动态数组
    scanf("%zd", &size);
    int data[size];
    printf("%u bytes.\n", sizeof(int));
    for (int i = 0; i < 5; ++i) {
        data[i] = 12 * (i + 1);
        printf("data[%d] Address: %p Contents: %d\n", i, &data[i], data[i]);
    }

    return 0;
}
