#include <stdio.h>
#include<windows.h>/
#define PI 3.1415926f
void test();

int main(void) {

    int nTmp = 0x00224000;
    int nData = *(volatile unsigned int *)&nTmp;// 此处换&nTmp成要读取的地址如0x00123456
    printf("&Tmp:0x%08x nData:%d\n",
            &nTmp, nData);

    return 0;
}

