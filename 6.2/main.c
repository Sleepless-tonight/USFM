//
// Created by shiliang on 2020-03-05.
//
//

#include <stdio.h>

int main(void) {
    char str1[] = "To be or not to be";
    printf("str1 , %u .\n", sizeof str1);
    char str2[] = ",that is the question";
    unsigned int count = 0;
    while (str1[count] != '\0') {
        ++count;
    }

    printf("The length of the string \"%s\" is %d characters.\n", str1, count);
    count = 0;
    while (str2[count] != '\0') {
        ++count;
    }
    printf("The length of the string \"%s\" is %d characters.\n", str2, count);


    char str3[] = "To be or not to %s be";

    char str4[] = ",that is the question";
    printf(str3, str4);

    return 0;
}
