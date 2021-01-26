//
// Created by shiliang on 2020-03-05.
//
//
#include <stdio.h>
int main(void){
    long a = 1L;
    long b = 2L;
    long c = 3L;
    double d = 4.0;
    double e = 5.0;
    double f = 6.0;
    printf("%u bytes.\n", sizeof(long));
    printf("a:%p ;\nb:%p ;\nc:%p.\n", &a, &b, &c);
    printf("%u bytes.\n", sizeof(double));
    printf("d:%p ;\ne:%p ;\nf:%p.", &d, &e, &f);

}
