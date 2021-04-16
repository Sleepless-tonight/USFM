//
// Created by shiliang on 2020-03-05.
//
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
    char delimiters[] = " \n\".,;:!?)(";     // Prose delimiters
    char buf[BUF_LEN];                     // Buffer for a line of keyboard input
    size_t str_size = INIT_STR_EXT;          // current memory to store prose
    char *pstr = malloc(str_size);         // Pointer to prose to be tokenized
    *pstr = '\0';                            // Set 1st character to null

    printf("Enter some prose with up to %d characters per line.\n"
           "Terminate input by entering an empty line:\n",
           BUF_LEN);

    while (true) {
        fgets(buf, BUF_LEN, stdin);             // Read a line of input
        if (buf[0] == '\n') { break; }                  // An empty line ends input
        if (strnlen(pstr, str_size) + strnlen(buf, BUF_LEN) + 1 > str_size) {
            str_size = strnlen(pstr, str_size) + strnlen(buf, BUF_LEN) + 1;
            pstr = realloc(pstr, str_size);
        }

    }


}