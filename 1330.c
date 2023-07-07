#include<stdio.h>

int main(){
    int a, b;
    scanf("%d%d", &a, &b);

    if(a == b){
        printf("==");
    }else{
        char m = a > b ? '>' : '<';
        printf("%c", m);
    }
    return 0;
}