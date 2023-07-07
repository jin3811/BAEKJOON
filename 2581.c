#include <stdio.h>
#define MAX_SIZE 10001

int main () {
    /* 에라토스테네스의 체 */
    int seive[MAX_SIZE] = {0,}; // 0부터 시작
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
    int m, n; // 입력받을 정수 m <= n
    int i;
    scanf("%d %d", &m, &n);
    int min = n + 1, sum = 0; // 범위내 소수 최솟값. 범위내의 가장 큰 값보다 1이 더 큰 값으로 초기화 / 범위 내 소수들의 합

    for (i = m; i <= n; i++) {
        if (seive[i]) {
            min = min > i ? i : min; 
            sum += i;
        }
    }
    if (min == n+1) { // min이 그대로 n인 경우, 즉 범위내에 소수가 발견되지 않으면
        printf("-1");
    } else {
        printf("%d\n%d", sum, min);
    }

    return 0;
}