//
// Created by shili on 2022/4/7.
//
#include "stdio.h"
#include "stdarg.h"

# define __STDC_WANT_LIB_EXT1__ 1

unsigned long long factorial(unsigned long long);

int main(void) {
    unsigned long long number = 0LL;
    printf("Enter an integer value:");
    scanf_s("%llu", &number);
    printf("The factorial of %llu is %llu\n", number, factorial(number));
    return 0;
}

unsigned long long factorial(unsigned long long n) {
    if (n < 2LL)
        return n;
    return n * factorial(n - 1LL);

}

double average(double vl, double v2, ...) {
    va_list parg;                                       // Pointer for variable argument list
    double sum = vl + v2;
    double value = 0.0;
    int count = 2;
    va_start (parg, v2);                                // Initialize argument pointer
    while ((value = va_arg (parg, double)) != 0.0) {
        sum += value;
        ++count;
    }
    va_end (parg);                                      // End variable argument process
    return sum / count;
}