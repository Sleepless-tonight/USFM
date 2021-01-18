//
// Created by shiliang on 2020-03-05.
//
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
int main(void){

    bool a = true;
    double x = 10.25;
    double less = 0.0;
    less = floor(x);
    label: ;
    --less;
    printf("test %.2f \n", less);


    goto label;



    --less;
    printf("test %.2f \n", less);
    --less;
    less = (less--);
    printf("test %.2f \n", less);

    printf("Hello\n world!");
    printf("Hello\t world!");
    return 0;
}
