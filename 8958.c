#include<stdio.h>

int main(){
    char arr[81]; // 퀴즈 결과
    int Tcase; // 테스트 케이스
    int score = 0; // 총합점수
    int scoretemp = 0; // 점수
    int idx = 0; // 문자열 인덱스, 널문자 판별을 위함

    scanf("%d", &Tcase);

    for (int i = 0; i < Tcase; i++) {
        scanf("%s", arr);
        score = 0; // 점수 관련 변수 초기화
        scoretemp = 0;
        idx = 0;
        while (arr[idx] != '\0') {
            if (arr[idx] == 'O') {
                scoretemp += 1;
                score += scoretemp;
            } else {
                scoretemp = 0;
            }
            idx++;
        }
        printf("%d\n", score);
        
    }
    
    return 0;
}