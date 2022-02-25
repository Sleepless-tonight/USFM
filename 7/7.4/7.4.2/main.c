//
// Created by shiliang on 2020-03-05.
//
//


#define __STDC_WANT_LIB_EXT1__ 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    unsigned long long *pPrimes = NULL;
    unsigned long long trial = 0;
    bool found = false;
    int total = 0;
    int count = 0;

    // 在这个例子中,可以输入要程序产生的质数个数。指针变量 pPrimes 引用一块用于存储所计算的质数的内存区。然而,在程序中没有一开始就定义内存。这块空间是在输入质数个数后分配的:
    printf("How many primes would you like -you'll get at least 4?");
    scanf("%d", &total);
    // 在提示后,输入的值存储在total中。下一行语句确保total至少是4。这是因为程序将定义并存储已知的前三个质数2、3、5。
    total = total < 4 ? 4 : total;
    // 然后,使用total的值分配适当数量的内存来存储质数:
    pPrimes = (unsigned long long *) malloc(total * sizeof(unsigned long long));
    if (!pPrimes) {
        printf("Not enough memory .It's the end I'm afraid .\n");
        return 1;
    }
    *pPrimes = 2ULL;
    *(pPrimes + 1) = 3ULL;
    *(pPrimes + 2) = 5ULL;
    count = 3;
    trial = 5ULL;
    while (count < total) {
        trial += 2ULL;
        for (int i = 1; i < count; ++i) {
            if (!(found = (trial % *(pPrimes + i)))) {
                break;
            }
        }
        if (found) {
            *(pPrimes + count++) = trial;
        }
    }
    for (int i = 0; i < total; ++i) {
        printf("%12llu", *(pPrimes + i));
        if (!((i + 1) % 5)) {
            printf("\n");
        }
    }
    printf("\n");
    free(pPrimes);
    pPrimes = NULL;
    return 0;
}