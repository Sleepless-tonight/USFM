//
// Created by shiliang on 2020-03-05.
//
//


#include <stdio.h>
int main(void) {
    int number = 0;
    // pnumber �����Ǹ�ָ�����
    int *pnumber = NULL;
    number = 10;
//    printf("number's address: %p\n", &number);
//    printf("number's value: %d\n\n", number);

    pnumber = &number;
    // pnumber �����ĵ�ַ
    printf("pnumber �����ĵ�ַ: %p\n", (void *) &pnumber);
    // pnumber �����Ĵ�С
    printf("pnumber �����Ĵ�С: %zd bytes\n", sizeof(pnumber));
    // pnumber �����洢��ֵ����һ������ number �ĵ�ַ��
    printf("pnumber �����洢��ֵ: %p\n", pnumber);
    // ͨ�� ȡ����������� ��� pnumber �����洢�ĵ�ַ�ı�����ֵ
    printf("pnumber �����洢�ĵ�ַ�ı�����ֵ: %d\n", *pnumber);

    printf("pnumber - 1:%p\n", pnumber - 1);
    printf("pnumber    :%p\n", pnumber);
    printf("pnumber + 1:%p\n", pnumber + 1);

    return 0;
}
