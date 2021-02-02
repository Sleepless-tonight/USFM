//
// Created by shiliang on 2020-03-05.
//
//

//#define __STDC_LIB_EXT1__ 1
#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <string.h>
int main(void) {
    char str11[] = "Peter piper picked a peck of pickled pepper.";
    char ch11 = 'p';
    char *pGot_char11 = str11;
    int count =0;
    while (pGot_char11 = strchr(pGot_char11, ch11)) {
        ++count;
        ++pGot_char11;
    }
    printf ("The character '%c' was found %d times in the following string:\n\"%s\"\n", ch11, count, str11);


    char str[] = "The quick brown fox";
    char ch ='q';
    char *pGot_char = NULL;
    pGot_char = strchr(str, ch);
    printf("pGot_char:%c\n", *pGot_char);

    int Number = 25;

    int *ppNumber = &Number;
    printf("Number 变量的地址： %p\n", ppNumber);
    printf("Number 变量的值： %d\n", *ppNumber);

    char str1[50] = "to be, or not to be,";
    char str2[] = "that is question.";
    int retval = strcat_s(str1, sizeof(str1), str2);
    printf("str1:%s\n", str1);

    char s[] = "test";
    char s2[10];
    unsigned int max = 3;
    strncpy_s(s2, sizeof(s2), s,3);
    printf("tes:%s.", s2);
    printf("test:%zu", strnlen(s2, sizeof(s2)));
    return 0;
}
