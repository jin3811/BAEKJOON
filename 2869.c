#include <stdio.h>

int main () {
    int a, b, v;
    scanf("%d %d %d", &a, &b, &v);
    printf("%d", (v-b)%(a-b) ? (v-b)/(a-b)+1 : (v-b)/(a-b)); 
    /* (v-b)/(a-b)가 깔끔하게 나누어 떨어지는 경우는 그 값이 출력이지만, 
    그렇지 않은 경우는 그값보다 큰 최소의 자연수가 정답이다 */
    return 0;
}