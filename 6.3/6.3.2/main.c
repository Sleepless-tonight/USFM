//
// Created by shiliang on 2020-03-05.
//
//

#include <stdio.h>
#define __STDC_LIB_EXT1__ 1
#include <string.h>
int main(void) {
    char str1[] = "To be or not to be";

    printf("The string: %zu", strnlen_s(&str1, sizeof str1));
    return 0;
}
