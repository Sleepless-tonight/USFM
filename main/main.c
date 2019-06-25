#include <stdio.h>
#define PI 3.1415926f
void test();

int main(void) {
    float a = 1000000000.000f;
    float b = 20.0f * PI;
    printf("你好");
    //命令行录入扫描
//    scanf("%f", &b);

    printf("数值 a ——> %5.2f \n-- \n""数值 b ——> %f", a, b);
    double c1;
    double c2;
    int d = 5;
    int e = 8;
    c1 = (double)(d + e) / 2;
    c2 = (d + e) / 2.0;

//    test();
    return 0;
}

void test() {
    printf("Hello # | world2!\a", 5);
}

/*
 *  本 main 方法用于 举例说明触发了隐式类型转换
 * int main()
{
    int i = -2;
    unsigned int j = 1;

    if( (i + j) >= 0 )
    {
        printf("i+j>=0\n");
    }
    else
    {
        printf("i+j<0\n");
    }

 //触发了隐式类型转换后的数据类型 用错误的 变量值的转换说明符 带来稀奇古怪的后果
    //printf("i+j=%u\n", i + j);
    printf("i+j=%d\n", i + j);

    return 0;
}*/
