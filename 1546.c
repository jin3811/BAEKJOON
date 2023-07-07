#include<stdio.h>

int main(){
    int n; // 과목 개수
    int score; // 점수 입력
    double average; // 과목 점수 평균
    int max = 0; // 점수 최댓값
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &score);
        max = max > score ? max : score; //최댓값 저장
        average += score; // 요소의 총합
    }
    average = average / (n*max) * 100; // (총합 / n) * (100/max)    
    printf("%f", average);
    return 0;
}