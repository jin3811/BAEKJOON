#include <stdio.h>
#define MAX_SIZE 123456 * 2 + 1

int main () {
    int seive[MAX_SIZE] = {0,};
    for (int i = 2; i < MAX_SIZE; i++) {
        seive[i] = 1; 
    }
    for (int i = 2; i < MAX_SIZE; i++) {
        if (seive[i]) { 
            for (int p = 2; i*p < MAX_SIZE; p++) {
                seive[i*p] = 0;
            }
        }
    }
    
    int n = 1;
    int cnt = 0;
    while (1) {
        cnt = 0;
        scanf("%d", &n);
        if (!n) break;

        for (int i = n + 1; i <= 2 * n; i++) {
            if (seive[i]) cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}