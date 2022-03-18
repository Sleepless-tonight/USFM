//
// Created by shiliang on 2020-03-05.
//

#define __STDC_WANT_LIB_EXT1__ 1

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define BUF_LEN 100         // Length of input buffer 输入缓冲区的长度
#define COUNT 5    // Initial number of strings  字符串的初始数量

// 试试看:使用指针对字符串排序

int main(void) {
    char buf[BUF_LEN];                                                                  //  Input buffer    输入缓冲区
    size_t str_count = 0;                                                               // Current string count     当前字符串数
    size_t capacity = COUNT;                                                            // Current maximum number of strings    当前字符串的最大数目

    /**
     * *表示指针，**表示指针的指针。
     * 对于多维数组 数组的名称 是数组第一个元素的地址
     * 对于多维数组 *数组的名称 是数组第一个维度，第一个元素的地址
     * 对于多维数组 **数组的名称 是数组第一个维度，第一个元素的地址
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
            capacity += capacity / 4; // 增加25%的容量
            if (!(psTemp = realloc(ps, capacity))) return 1;
            ps = psTemp;
        }
        str_len = strnlen_s(buf, BUF_LEN) + 1;
        if (!(ps[str_count] = malloc(str_len)))return 2;
        strcpy_s(ps[str_count++], str_len, buf);
    }
    // 将字符串按升序排序

    return 0;
}