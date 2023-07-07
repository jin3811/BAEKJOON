#include <stdio.h>
#include <math.h>

int main () {
    int n, a, b, min = 9000;
    int i, j;
    scanf("%d", &n);
    a = ceil((double)n / 5);
    b = ceil((double)n / 3);

    for (i = 0; i <= a; i++) {
        for (j = 0; j <= b; j++) {
            if (5 * i + 3 * j == n) 
                min = min > i + j ? i + j : min;
        }
    }
    printf("%d\n", min == 9000 ? -1 : min);
    return 0;
}