#include <stdio.h>

int gcd (int a, int b) { 
    /* Ucildian gcd algorithm */
    int rest = 1;
    if (a < b) {
        int temp = b;
        b = a;
        a = temp;
    }
    while(rest != 0){ 
        rest = a % b; 
        a = b; // a -> b
        b = rest; // b -> r1
    }
    return a;
}

int main () {
    int T, a, b, x, temp;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &a, &b);

        while (a != 1) {
            x = b/a + 1;
            a = a*x - b;
            b *= x;
            temp = gcd(a, b);
            a /= temp;
            b /= temp;
        }
        printf("%d\n", b);
    }
    return 0;
}