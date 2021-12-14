//
// Created by shiliang on 2020-03-05.
//
//

#define __STDC_WANT_LIB_EXT1__ 1
#define MAX_LENGTH 21

#include <stdio.h>
#include <string.h>

int main(void) {
    char word1[MAX_LENGTH];
    char word2[MAX_LENGTH];
    printf("Type in the first word (maximum %d characters): ", MAX_LENGTH - 1);
    int retval = scanf_s("%s", word1, sizeof(word1));
    printf("\nretval %d\nY", retval);

    if (EOF == retval) {
        printf("Error reading the word.\n");
        return 1;
    }
    printf("Type in the first word (maximum %d characters):", MAX_LENGTH - 1);
    retval = scanf_s("%s", word2, sizeof(word2));
    printf("\nretval2 %d\nY", retval);

    // #define EOF (-1) 但是 超出字符数后 scanf_s()函数返回的是 0
    if (EOF == retval) {
        printf("Error reading the word.\n");
        return 2;
    }
    if (strcmp(word1, word2) == 0) {
        printf("ou have entered identical words.");
    } else {
        printf("%s precedes %s\n", (strcmp(word1, word2) < 0 ? word1 : word2),
               (strcmp(word1, word2) < 0 ? word2 : word1));
    }


}
