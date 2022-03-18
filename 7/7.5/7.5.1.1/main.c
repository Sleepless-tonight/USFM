//
// Created by shiliang on 2020-03-05.
// 7.5.1 适用指针数组
//

#define __STDC_WANT_LIB_EXT1__ 1

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define BUF_LEN 100         // Input buffer size
#define INIT_STR_EXT 50     // Initial space for prose
#define WORDS_INCR 5        // words capacity increment


int main(void) {

#define STR_COUNT 10
    const size_t BUF_SIZE = 100;
    char buffer[BUF_SIZE];
    char *ps[STR_COUNT] = {NULL};

    size_t str_size = 0;
    for (size_t i = 0; i < STR_COUNT; ++i) {
        scanf_s("%s", buffer, BUF_SIZE);    // Read a string
        // Allocate space for the string
        str_size = strnlen(buffer, BUF_SIZE) + 1;
        ps[i] = malloc(str_size);
        if (!ps[i]) return 1;
        strcpy_s(ps[i], str_size, buffer); // copy string to new memory
    }
    for (size_t i = 0; i < STR_COUNT; ++i) {
        printf("%s \n", ps[i]);
        free(ps[i]);
        ps[i] = NULL;
    }

    return 0;
}