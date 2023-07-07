#include <stdio.h>
#include <math.h>

#define ULL unsigned long long
#define A (1 + sqrt(5)) / 2
#define B (1 - sqrt(5)) / 2

int fibo(int n) {
    return (int)(((pow(A, n) - pow(B, n)) / sqrt(5)));
}

int main () {
    int n;
    scanf("%d", &n);
    printf("%d", fibo(n));
}