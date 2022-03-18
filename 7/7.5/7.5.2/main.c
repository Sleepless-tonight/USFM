//
// Created by shiliang on 2020-03-05.
//

#define __STDC_WANT_LIB_EXT1__ 1

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define BUF_LEN 100         // Length of input buffer ���뻺�����ĳ���
#define COUNT 5    // Initial number of strings  �ַ����ĳ�ʼ����

// ���Կ�:ʹ��ָ����ַ�������

int main(void) {
    char buf[BUF_LEN];                                                                  //  Input buffer    ���뻺����
    size_t str_count = 0;                                                               // Current string count     ��ǰ�ַ�����
    size_t capacity = COUNT;                                                            // Current maximum number of strings    ��ǰ�ַ����������Ŀ

    /**
     * *��ʾָ�룬**��ʾָ���ָ�롣
     * ���ڶ�ά���� ��������� �������һ��Ԫ�صĵ�ַ
     * ���ڶ�ά���� *��������� �������һ��ά�ȣ���һ��Ԫ�صĵ�ַ
     * ���ڶ�ά���� **��������� �������һ��ά�ȣ���һ��Ԫ�صĵ�ַ
     *
     */
    char **ps = calloc(capacity, sizeof(char *));
    char **psTemp = NULL;
    char *pTemp = NULL;
    size_t str_len = 0;
    bool sorted = false;
    printf("Enter strings to be sorted, one per line. Press Enter to end:\n");
    char *ptr = NULL;
    while (true) {
        ptr = fgets(buf, BUF_LEN, stdin);
        if (!ptr) {
            printf("Error reading string.\n");
            free(ps);
            ps = NULL;
            return 1;
        }
        if (*ptr == '\n') break;
        if (str_count == capacity) {
            capacity += capacity / 4; // ����25%������
            if (!(psTemp = realloc(ps, capacity))) return 1;
            ps = psTemp;
        }
        str_len = strnlen_s(buf, BUF_LEN) + 1;
        if (!(ps[str_count] = malloc(str_len)))return 2;
        strcpy_s(ps[str_count++], str_len, buf);
    }
    // ���ַ�������������

    return 0;
}