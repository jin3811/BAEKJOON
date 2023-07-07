#include <stdio.h>
#include <math.h>

#define ULL unsigned long long
#define SIZE 91

ULL fibo(int n) {
    static ULL fiboarr[SIZE] = {0,1};
    if (n <= 1) return n;
    else if (fiboarr[n]) return fiboarr[n];
    else {
        fiboarr[n] = fibo(n-1) + fibo(n-2);
        return fiboarr[n];
    }
}

int main () {
    int n;
    scanf("%d", &n);
    printf("%lld", fibo(n));
}