#include <stdio.h>
#define r 31
#define M 1234567891

int main () {
    int l, i;
    char arr[51];
    long long hash = 0, R = 1;

    scanf("%d %s", &l, arr);

    for (i = 0; i < l; i++) {
        hash += ((arr[i] - 'a' + 1) * R) % M; hash %= M;
        R *= r; R %= M;
    }
    printf("%lld", hash % M);
    return 0;
}