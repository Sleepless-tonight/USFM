//
// Created by shiliang on 2020-03-05.
//
//

#include <stdio.h>
#define __STDC_LIB_EXT1__ 1
#include <string.h>
int main(void) {
#if defined __STDC_LIB_EXT1__
    printf("P1\n");
#else
    printf("P2\n");
#endif
    return 0;
}
