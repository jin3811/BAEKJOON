#include<stdio.h>

int main(){
    int T;
    int a,b;
    int i;

    scanf("%d", &T);
    int sum[T];

    for(i = 0; i < T; i++){
        scanf("%d %d", &a, &b);
        printf("Case #%d: %d + %d = %d\n", i+1, a, b, a+b);
        // sum[i] = a+b;
    }
    // for(i = 0; i < T; i++){
    //     printf("Case #%d: %d\n", i+1, sum[i]);
    // }
    return 0;
}