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
    printf("number's address: %p\n", &number);
    printf("number's value: %d\n\n", number);
    pnumber = &number;
    // pnumber �����ĵ�ַ
    printf("pnumber's address: %p\n", (void *) &pnumber);
    // pnumber �����Ĵ�С
    printf("pnumber's size: %zd bytes\n", sizeof(pnumber));
    // pnumber �����洢��ֵ����һ������ number �ĵ�ַ��
    printf("pnumber's value: %p\n", pnumber);
    // ͨ�� ȡ����������� ��� pnumber �����洢�ĵ�ַ�ı�����ֵ
    printf("value pointed to: %d\n", *pnumber);
    return 0;
}
