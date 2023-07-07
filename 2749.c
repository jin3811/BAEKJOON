#include <stdio.h>
#define SIZE 1500000
#define MOD 1000000

int main () {
    long long n;
    int arr[SIZE] = {0, 1};

    for (int i = 2; i < SIZE; i++)
        arr[i] = (arr[i - 1] + arr[i - 2]) % MOD;
    scanf("%lld", &n);
    printf("%d", arr[n % SIZE]);
}