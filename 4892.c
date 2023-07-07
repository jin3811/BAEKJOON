#include <stdio.h>

int main () {
    int n;
    int i = 0;
    while (1) {
        scanf("%d", &n);
        if (!n) break;
        printf("%d. %s %d", i++, n%2 ? "odd" : "even", n/2);
    }
    return 0;
}