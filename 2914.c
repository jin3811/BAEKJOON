#include <stdio.h>

int main () {
    int n, avg;
    scanf("%d %d", &n, &avg);
    printf("%d", n * (avg - 1) + 1);
    return 0;
}