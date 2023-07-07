#include <stdio.h>
#include <stdlib.h>

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
    int N, i, g;
    int * arr = NULL;
    
    scanf("%d", &N);
    arr = malloc(N * sizeof(int));
    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = 1; i < N; i++) {
        g = gcd(arr[0], arr[i]);
        printf("%d/%d\n", arr[0]/g, arr[i]/g);
    }
    return 0;
}