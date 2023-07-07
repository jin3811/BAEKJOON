#include <stdio.h>

int main () {
    int seive[10001] = {0, 0};
    for (int i = 2; i < 10001; i++) {
        seive[i] = 1; 
    }
    for (int i = 2; i < 10001; i++) {
        if (seive[i]) { 
            for (int p = 2; i*p < 10001; p++) {
                seive[i*p] = 0;
            }
        }
    }
    int T, n, gold_part;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        gold_part = n >> 1; // 절반값
        while (gold_part) {
            if (seive[gold_part] && seive[n - gold_part])
                break;
            else
                gold_part--;
        }
        printf("%d %d\n", gold_part, n - gold_part);
    }
    return 0;
}