#include <stdio.h>

void hanoi (int num, int from, int temp, int to) {
    if (num == 1) printf("%d %d \n", from , to);
    else {
        hanoi(num - 1, from, to, temp);
        printf("%d %d\n", from, to);
        hanoi(num - 1, temp, from, to);
    }
}

int main () {
    int input;
    scanf("%d", &input);
    printf("%d \n", (1 << input) - 1);
    hanoi(input, 1, 2, 3);
    return 0;
}