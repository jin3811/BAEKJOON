#include <stdio.h>
#define pi 3.14159265358979

int main () {
    int r;
    scanf("%d", &r);
    printf("%.6f \n", r * r * pi); // 유클리드 기하학 - 원의 넓이 : pi*(r^2)
    printf("%.6f \n", 2.0 * r * r); // 택시 기하학의 - 원의 넓이 : ((2r)^2)/2 = 2*(r^2)
    return 0;
}