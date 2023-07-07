#include<stdio.h>

int main(){
    int T;
    int a,b;
    int i;

    scanf("%d", &T);
    int sum[T];

    for(i = 0; i < T; i++){
        scanf("%d %d", &a, &b);
        sum[i] = a+b;
    }
    for(i = 0; i < T; i++){
        printf("%d\n", sum[i]);
    }
    return 0;
}