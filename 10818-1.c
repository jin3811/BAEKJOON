#include<stdio.h>

int main(){
    int user;
    int max = -1000000, min = 1000000; // �ִ�, �ּڰ�
    int i;
    scanf("%d", &user); // N���� ������ �Է¹޴´�

    int arr[user]; // N���� ������ �Է� ���� �迭
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