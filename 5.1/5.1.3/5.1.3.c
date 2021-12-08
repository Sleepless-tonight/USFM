//
// Created by shili on 2021/12/8.
//
#include <stdio.h>

int main(void) {
    int grades[10];
    unsigned int count = 10;
    long sum = 0L;
    float average = 0.0f;
    printf("\nEnter the 10 grades:\n");
    // 此处多加一个空格，否者第一行 ‘printf("%2u> ", i + 1);’指挥格式化1个空格位置
    for (unsigned int i = 0; i < count; ++i) {
        printf("%2u>", i + 1);
        scanf("%d", &grades[i]);
        sum += grades[i];

    }
    average = (float) sum / count;
    printf("\nAverage of the ten grades entered is: %.2f\n", average);
    return 0;
}