//
// Created by shiliang on 2020-03-05.
//
//


#include <stdio.h>

int main(void) {
    long value = 9999L;
    long const *pvalue = &value;
    // *pvalue = 8888L;             // ֻ���������ɸ�ֵ
    value = 7777L;                  // pvalue ָ���ֵ���ܸı�,�����Զ� value �������������
    long number = 8888L;
    pvalue = &number;               // ָ�뱾���ǳ���

    /*
     * ָ������ָ��
     * ���Ըı�ָ���д洢�ĵ�ַ,��������ʹ��ָ��ı���ָ���ֵ
     * */

    return 0;
}
