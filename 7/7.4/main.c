//
// Created by shiliang on 2020-03-05.
//
//


#include <stdio.h>

int main(void) {
    char multiple[] = "My string";

    char *p = &multiple[0];
    printf("The address of the first array element : %p\n", p);
    p = multiple;
    printf("The address obtained from the array name: %p\n", multiple);
    return 0;
    /**
     * ���Դ�������������еõ�һ������: &multiple[0]�������multiple���ʽ��ͬ��ֵ��
     * ����������������,��Ϊ multiple ���������һ���ֽڵĵ�ַ, &multple[0]���������
     * һ��Ԫ�صĵ�һ���ֽ�,������ǲ�ͬ,�����˾��ȡ�
     */
}