#include<stdio.h>

int main(){
    int c, n, cnt; // 테스트케이스, 학생 수, 평균 넘은 사람
    double avg; // 평균

    scanf("%d", &c); //테스트 케이스 입력

    for (int i = 0; i < c; i++) {
        avg = 0; // 평균과 평균 넘은사람 초기화
        cnt = 0;

        scanf("%d", &n); // 학생수 입력
        int score[n]; // 학생 수에 맞는 길이의 배열
        
        for (int j = 0; j < n; j++) {
            scanf("%d", &score[j]); // 점수 입력
            avg += score[j]; // 점수를 총합
        }
        avg /= n; //평균 구함

        for (int k = 0; k < n; k++) {
            if (score[k] > avg) { // 평균을 넘는 사람 세기
                cnt++;
            }
        }
        printf("%.3f%%\n", 100*(double)cnt/n);
    }
    return 0;
}