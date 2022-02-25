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

    // �����������,��������Ҫ�������������������ָ����� pPrimes ����һ�����ڴ洢��������������ڴ�����Ȼ��,�ڳ�����û��һ��ʼ�Ͷ����ڴ档���ռ�����������������������:
    printf("How many primes would you like -you'll get at least 4?");
    scanf("%d", &total);
    // ����ʾ��,�����ֵ�洢��total�С���һ�����ȷ��total������4��������Ϊ���򽫶��岢�洢��֪��ǰ��������2��3��5��
    total = total < 4 ? 4 : total;
    // Ȼ��,ʹ��total��ֵ�����ʵ��������ڴ����洢����:
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