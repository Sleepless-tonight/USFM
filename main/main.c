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

