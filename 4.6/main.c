//
// Created by shili on 2021/1/20.
//
#include "stdio.h"
int main(void){
    unsigned long long int sum = 0LL;
    unsigned int count = 0;
    printf("\nEnter the number of integers you want to sum:");
    scanf("%u", &count);
    for (int i = 1; i <= count; sum += i++) ;
    printf("\nTotal of the first %u numbers is %llu\n", count, sum);
    return 0;
}