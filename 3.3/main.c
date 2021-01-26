//
// Created by shiliang on 2020-03-05.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
int main(void){
    unsigned int original = 0xABC;
    unsigned int result = 0;
    unsigned int mask = 0xF;    // Rightmost four bits 最右边的四位
    printf("\n original = %X", original);

    // insert first digit in result
    result |= original & mask;  // Put right 4 bits from original in result 将结果从原位置右移4位
    // Get second digit 得到第二位数
    original >>= 4;             // shift original right four positions 移动原始的右四个位置
    result <<= 4;               // Make room for next digit 给下一位腾出位置
    result |= original & mask;  // Put right 4 bits from original in result 将结果从原来的4位右移

    // Get third digit 得到第二位数
    original >>= 4;             // Shift oriqinal right four positions  向右移动原来的四个位置
    result <<= 4;               // Make room for next digit 给下一位腾出位置
    result |= original & mask;  // Put right 4 bits from original in result 返回结果的右4位
    printf("\t result = %X\n", result);
    return 0;






    printf("test %x \n", original);
    char s[20];
    itoa(original, s, 2);
    printf("二进制 --> %s\n", s);
}
