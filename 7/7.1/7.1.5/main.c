//
// Created by shiliang on 2020-03-05.
//
//


#include <stdio.h>

int main(void) {


    int count = 43;
    int *const pcount = &count; //����ָ��

    *pcount = 345;

    int item = 34;
    // pcount = &item;

    /*
     * ����ָ��
     * ָ���д洢�ĵ�ַ���ܸı�
     * */

    const long *pvalue = &count;        // ָ������ָ��
    int *const pcount2 = &count;        // ����ָ��
    const int *const pitem = &count;    // ָ�����ĳ���ָ��
                                        // ���е���Ϣ���̶�����

    return 0;
}
