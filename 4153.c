#include <stdio.h>

int cheaker (int a, int b, int c) {
    int temp;
    if (a > c) {
        temp = a;
        a = c;
        c = temp;
    } else if (b > c) {
        temp = b;
        b = c;
        c = temp;
    }
    return a*a + b*b == c*c;
}

int main () {
    int a=1,b=1,c=1;
    
    while (1) {
        scanf("%d%d%d", &a, &b ,&c);
        if (a == 0 && b == 0 && c == 0) break;
        printf(cheaker(a,b,c) ? "right\n" : "wrong\n");
    }

    
    return 0;
}