#include <stdio.h>
#include <stdbool.h>
#define SIZE 1000001

int main () {
    bool seive[SIZE] = {false, false}; // 0부터 시작 (0,1,2,3....), 0은 계산의 편의성을 위해 넣음, 1은 소수도 합성수도 아니므로 false
    int m,n;
    scanf("%d%d", &m, &n);

    for (int i = 2; i < SIZE; i++) {
        seive[i] = true; // 일단 2 이상의 모든 숫자들을 true로 초기화
    }
    for (int i = 2; i < SIZE; i++) {
        if (seive[i]) { // 만약 지워지지 않은 숫자라면
            for (int p = 2; i*p < SIZE; p++) {
                seive[i*p] = false; //그 배수들을 모두 지운다
            }
        }
    }

    for (int i = m; i <= n; i++) {
        if (seive[i]) printf("%d\n", i);
    }
    return 0;
}