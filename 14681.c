#include<stdio.h>

int main(){
    int x, y;
    int quad;

    scanf("%d", &x); scanf("%d", &y);
    if(x > 0){
        quad = y > 0 ? 1 : 4;
    } else{
        quad = y > 0 ? 2 : 3;
    }

    printf("%d", quad);
    return 0;
}