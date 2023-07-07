#include <stdio.h>
#include <stdbool.h>

int main () {
    int t, n, square;
    bool flag;
    scanf("%d", &t);
    while (t--) {
        flag = true;
        scanf("%d", &n);
        square = n*n;
        while (n) {
            if (n % 10 != square % 10) flag = false;
            n/=10; square /= 10;
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}