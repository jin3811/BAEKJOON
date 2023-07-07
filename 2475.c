#include <stdio.h>

int main () {
    int a, total = 0;
    
    for (int i = 0; i < 5; i++) {
        scanf("%d", &a);
        total += a * a;
        
    }
    printf("%d",total % 10);
    return 0;
}