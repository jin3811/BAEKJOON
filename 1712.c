#include <stdio.h>

int main () {
    int a,b,c; // 고정비용, 가변비용, 판매단가
    int bep = 0; // 손익 분기점
    scanf("%d %d %d", &a, &b, &c);

    if (b >= c) {
        printf("-1");
    } else {
        bep = (double) a / (c-b);
        printf("%d", ++bep);
    }
    return 0;
}