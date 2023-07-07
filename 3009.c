#include <stdio.h>

int main () {
    int arr[6];/* x1, y1, x2, y2, x3, y3 */
    int x, y;
    for (int i = 0; i < 6; i++) {
        scanf("%d", &arr[i]);
    }

    if (arr[0] == arr[2]) {
        x = arr[4];
    } else if (arr[0] == arr[4]) {
        x = arr[2];
    } else {
        x = arr[0];
    }

    if (arr[1] == arr[3]) {
        y = arr[5];
    } else if (arr[1] == arr[5]) {
        y = arr[3];
    } else {
        y = arr[1];
    }

    printf("%d %d", x, y);
    return 0;
}