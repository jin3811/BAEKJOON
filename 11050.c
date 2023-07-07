#include <stdio.h>

int fac (int n) {
    int res = 1;
    while (n > 1) {
        res *= n--;
    }
    return res;
}

int combination (int n, int r) {
    return fac(n) / (fac(r) * fac(n-r));
}

int main () {
    int n, r;

    scanf("%d %d", &n, &r);
    printf("%d", combination(n, r));
    
    return 0;
}