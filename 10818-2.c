#include<stdio.h>

int main(){
    int user;
    int max = -1000000, min = 1000000; // ÃÖ´ñ°ª, ÃÖ¼Ú°ª
    int temp;

    scanf("%d", &user);

    for(int i = 0; i < user; i++){
        scanf("%d", &temp);

        max = max < temp ? temp : max;
        min = min > temp ? temp : min;
    }
    
    printf("%d %d", min, max);
    return 0;
}