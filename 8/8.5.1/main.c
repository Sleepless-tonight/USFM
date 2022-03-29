//
// Created by shiliang on 2020-03-05.
//
//

#define __STDC_WANT_LIB_EXT1__ 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BUF_LEN 256         // Input buffer size
#define INIT_NSTR 2         // Initial number of strings
#define NSTR_INCR 2         // increment to number to strings

char *str_in();                           // Reads a string
void str_sort(const char **, size_t);       // Sorts an array of strings
void swap(const char **, const char **);    // Swaps two pointers
void str_out(const char *const *, size_t);  // Outputs the strings¡¢
void free_memory(char **, size_t);          // Free all heap memory
int main(void) {
    size_t pS_size = INIT_NSTR;
    char **pS = calloc(pS_size, sizeof(char *));
    if (!pS) {
        printf("Failed to allocate memory for string pointers.In");
        exit(1);
    }

    char **pTemp = NULL;
    size_t str_count = 0;
    char *pStr = NULL;
    printf("Enter one string per line. Press Enter to end: \n");
    while ((pStr = str_in()) != NULL) {
        if (str_count == pS_size) {
            pS_size += NSTR_INCR;
            if (!(pTemp = realloc(pS, pS_size * sizeof(char *)))) {
                printf("Memory allocation for array of strings failed. In");
                return 2;
            }
            pS = pTemp;
        }
        pS[str_count++] = pStr;
    }
    str_sort(pS, str_count);
    str_out(pS, str_count);
    free_memory(pS, str_count);

    return 0;
}

char *str_in(void) {
    char buf[BUF_LEN];
    if (!gets_s(buf, BUF_LEN)) {
        printf("\nError reading string. \n");
        return NULL;
    }
    if (buf[0] == '\0') {
        return NULL;
    }
    size_t str_len = strnlen_s(buf, BUF_LEN) + 1;
    char *pString = malloc(str_len);
    if (!pString) {
        printf("Memory allocation failure.\n");
        return NULL;
    }
    strcpy_s(pString, str_len, buf);
    return pString;
}

void str_sort(const char **p, size_t n) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < n - 1; ++i) {
            if (strcmp(p[i], p[i + 1]) > 0) {
                sorted = false;
                swap(&p[i], &p[i + 1]);
            }
        }
    }
}

void swap(const char **pl, const char **p2) {
    const char *pT = *pl;
    *pl = *p2;
    *p2 = pT;
}


void str_out(const char *const *pStr, size_t n) {
    printf("The sorted strings are:\n");
    for (size_t i = 0; i < n; ++i)
        printf("%s\n", pStr[i]);// Display a string

}

void free_memory(char **pS, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        free(pS[i]);
        pS[i] = NULL;
    }
    free(pS);
    pS = NULL;
}










