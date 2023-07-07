#include <stdio.h>

// Recursive solution
long long fac (int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * fac(n-1);
    }
}

int main () {
    int a;
    scanf("%d", &a);
    printf("%d", fac(a));
    return 0;
}

// loop solution
/*
int main () {
    int a;
    long long result = 1;

    scanf("%d", &a);
    for (int i = 2; i <= a; i++) {
        result *= i;
    }
}
*/