#include<stdio.h>

int nat_pow(int base, int exponent){
    int n = 1;
    if(exponent != 0){
        for(int i = 0; i < exponent; i++){
            n *= base;
        }
    }
    return n;
}

int main(){
    int a;
    int temp;
    int sum = 0;
    char b[4];
    // int *pa = 
    scanf("%d", &a);
    scanf("%s", b);
    // printf("%d %s\n", a, b);
    // printf("\npointer\na: %x(%d)\nb: %x(%d)\n", &a, &a, &b, &b);
    for(int i = 0; i < 3; i++){
        temp = b[2-i] - '0';
        printf("%d\n", a * temp);
        sum += a * temp * nat_pow(10, i);
    }
    printf("%d", sum);
    return 0;
}