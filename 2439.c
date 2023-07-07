#include<stdio.h>

int main(){
    int N;
    scanf("%d", &N);

    for(int i = 1; i <= N; i++){ // 1 2 3 4 5
        for(int j = 0; j < N-i; j++){ // 4 3 2 1 0
            printf(" ");
        }
        for(int k = 0; k < i; k++){ // 0
            printf("*");
        }
        printf("\n");
    }
}