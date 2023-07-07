#include <stdio.h>

int main () {
    int n, temp, max = 2, min = 1000000;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &temp);
        max = max < temp ? temp : max;
        min = min > temp ? temp : min;
    }
    printf("%d", max * min);
    return 0;
}