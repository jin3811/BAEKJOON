#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b) {
    int x = *(int *)a;
    int y = *(int *)b;

    return x < y;
}

int main () {
    int temp, len = 0;
    int number[10];
    scanf("%d", &temp);
    for (int i = 0; temp != 0; i++) {
        number[i] = temp%10;
        temp /= 10;
        len++;
    }
    qsort(number, len, sizeof(int), compare);

    for (int i = 0; i < len; i++) {
        printf("%d", number[i]);
    }
}