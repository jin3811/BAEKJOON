#include <stdio.h>

int main () {
    int t, a, b, result;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &a, &b);
        result = 1;
        for (int i = 0; i < b; i++) {
            result *= a%10;
            result %= 10;
        }
        printf("%d\n", result ? result : 10);
    }
}