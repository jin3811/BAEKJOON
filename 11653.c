#include <stdio.h>

int main () {
    int n;
    scanf("%d", &n);
    int x = 2;

    while (n != 1) {
        if (n % x == 0) {
            printf("%d\n", x);
            n /= x;
        } else {
            x++;
        }
    }
    return 0;
}