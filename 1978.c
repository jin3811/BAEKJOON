#include <stdio.h>
#include <stdbool.h>

int main () {
    bool seive[1001] = {false, false};
    for (int i = 2; i < 1001; i++) {
        seive[i] = true; 
    }
    for (int i = 2; i < 1001; i++) {
        if (seive[i]) { 
            for (int p = 2; i*p < 1001; p++) {
                seive[i*p] = false;
            }
        }
    }

    int n, cnt = 0;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (seive[arr[i]]) cnt++;
    }
    printf("%d", cnt);
    return 0;
}
