//
// Created by shiliang on 2020-03-05.
//
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    const size_t BUF_SIZE = 100;         // Input buffer size
    char buffer[BUF_SIZE];             // A 100 byte input buffer
    scanf_s("%s", buffer, BUF_SIZE);    // Read a string
    // Allocate space for the string
    size_t length = strnlen(buffer, BUF_SIZE) + 1;
    char *pstring = malloc(length);
    if (!pstring) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    strcpy_s(pstring, length, buffer); // copy string to new memory
    printf("%s", pstring);
    free(pstring);
    pstring = NULL;
}