#include<stdio.h>

int main(){
    int arr[9]; // 길이 9의 int형 배열 선언
    int max = 0; // 최댓값을 찾을 int형 변수
    int idx; // max의 위치를 찾을 int형 변수

    for(int i = 0; i < 9; i++){
        scanf("%d", &arr[i]); // 정수를 입력받아 arr[i]에 저장
        if (max < arr[i]) { // max보다 클 경우
            max = arr[i]; // arr[i]를 max에 대입
            idx = i+1; // i+1을 idx에 대입. (배열의 인덱스 + 1 = n번째)
        }
    }
    // for(int i = 0; i < 9; i++){
    //     printf("arr[%d]: %d\n", i, arr[i]);
    // }
    printf("%d\n%d", max, idx);
    return 0;
}