#include <stdio.h>
#include <stdlib.h>

int main () {
    int n, m, max = 0, sum;
    int * arr = NULL;
    int i, j, k;
    scanf("%d %d", &n, &m);
    arr = malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n - 2; i++) {
        for (j = i + 1; j < n - 1; j++) {
            for (k = j + 1; k < n; k++) {
                sum = arr[i] + arr[j] + arr[k];
                if (sum <= m)
                    max = max < sum ? sum : max;
            }
        }
    }
    printf("%d", max);
    return 0;
}