#include <stdio.h>
#include <math.h>

int main () {
    int t;
    int x, y;
    double dis;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &x, &y);
        dis = sqrt(y-x);
        if (dis == (int)dis) { // 거리가 제곱수라면 2sqrt(n)-1회
            printf("%d\n", 2 * (int)dis - 1);
        } else {
            printf("%d\n", (int)(2 * dis));
        }
    }
}