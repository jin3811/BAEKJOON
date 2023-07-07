#include <stdio.h>

int arithmetic_sum (int d, int n) { // 공차, 더하는  범위
    int temp = 0;
    int result = 1;

    if (n != 1) {
        for (int i = 1; i < n; i++) {
            temp += d;
            result += temp;
        }
    }
    return result;
}

int main () {
    int result = 0;
    int N;

    scanf("%d", &N);

    while (1) {
        if (N == 1) break;
        if (arithmetic_sum(6, result) < N && arithmetic_sum(6, result+1) >= N) {
            break;
        } else {
            result++;
        }
    }
    printf("%d", result + 1);
}