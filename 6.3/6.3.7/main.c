//
// Created by shiliang on 2020-03-05.
//My father's family name being Pirrip, and my christian name Philip,
//my infant tonque could make of both names nothing longer
//or more explicit than Pip.
//So, I called myself Pip, and came to be called Pip.
//

#define __STDC_WANT_LIB_EXT1__ 1

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void) {
    char delimiters[] = "\".;:!?) (";
    char buf[100];
    char str[1000];
    char *ptr = NULL;
    str[0] = '\0';
    size_t str_len = sizeof(str);
    size_t buf_len = sizeof(buf);
    printf("Enter some prose that is less than %zd characters.\n" "Terminate input by entering an empty line:\n",
           str_len);
    while (true) {
        if (!gets(buf)) {
            printf("Error reading string.\n");
            return 1;
        }
        if (!strnlen(buf, buf_len)) {
            break;
        }
        if (strcat_s(str, str_len, buf)) {
            printf("Maximum permitted input length exceeded.\n");
            return 1;
        }

    }
    printf("The words in the prose that you entered are:\n", str);
    // Find and list all the words in the prose
    unsigned int word_count = 0;
//    char *pWord = strtok_s(str, &str_len, delimiters, &ptr); // Find 1st word
    char *pWord = strtok_s(str, delimiters, &ptr); // Find 1st word
    if (pWord) {
        do {
            printf("%-18s", pWord);
            if (++word_count % 5 == 0)
                printf("\n");
//            pWord = strtok_s (NULL, &str_len, delimiters, &ptr);
            pWord = strtok_s(NULL, delimiters, &ptr);

        } while (pWord);
        printf("\n%u words found.\n", word_count);
    } else {
        printf("No words found.\n");
    }
    return 0;
}
