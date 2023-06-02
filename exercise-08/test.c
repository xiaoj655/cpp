#include <stdio.h>
// #include <float.h>

int main() {
    double d = 123.456789e100; // 超出float类型的取值范围
    float f = (float)d;

    printf("d = %lf\n", d);
    printf("f = %f\n", f);   // 输出结果为inf

    d = 1.234567890123456789; // 精度损失
    f = (float)d;

    printf("d = %.20lf\n", d); 
    printf("f = %.20f\n", f); // 输出结果为1.23456788063049320000

    return 0;
}