#include<stdio.h>

int main(){
    int user;
    int max = -1000000, min = 1000000; // 최댓값, 최솟값
    int i;
    scanf("%d", &user); // N개의 정수를 입력받는다

    int arr[user]; // N개의 정수를 입력 받을 배열
    for(i = 0; i < user; i++){ 
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < user; i++){
        // if(max < arr[i]){
        //     max = arr[i];
        // }
        // if(min > arr[i]){
        //     min = arr[i];
        // }
        max = max < arr[i] ? max : arr[i];
        min = min > arr[i] ? min : arr[i];
    }
    printf("%d %d", min, max);
    return 0;
}