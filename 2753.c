#include<stdio.h>

int main(){
    int year;
    int res = 0;

    scanf("%d", &year);
    if(year % 400 == 0){
        res = 1;
    } else if (year % 4 == 0 && year % 100 != 0){
        res = 1;
    }
    printf("%d", res);
    return 0;
}