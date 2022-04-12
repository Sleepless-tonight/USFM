//
// Created by shili on 2022/4/7.
//
#include "stdio.h"
#include "stdarg.h"

double average(double vl, double v2, ...);

int main(void) {
    double v1 = 10.5, v2 = 2.5;
    int num1 = 6, num2 = 5;
    long num3 = 12L, num4 = 20L;
    printf("Average = %.2lf\n", average(v1, 3.5, v2, 4.5, 0.0));
    printf("Average = %.2lf\n", average(1.0, 2.0, 0.0));
    printf("Average = %.2lf\n", average((double) num2, v2, (double) num1, (double) num4, (double) num3, 0.0));
    return 0;
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