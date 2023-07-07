#include<stdio.h>

int main(){
    int num; // 입력받을 정수
    int cnt=0; // 서로 다른 나머지의 개수를 저장할 변수
    int rest[10]; // 나머지를 저장할 배열
    int i; // 반복문을 위한 인자

    for(i = 0; i < 10; i++){ //입력
        scanf("%d", &num);
        rest[i] = num % 42;
    }

    for(i = 0; i < 10; i++){ // 개수 세기
        if (rest[i] != -1) {
            cnt++; // cnt 1 증가
            for (int j = i+1; j < 10; j++){ 
                if (rest[i] == rest[j]){
                    rest[j] = -1; // 이후의 같은 값들을 -1로 만들어 무시하도록 한다.
                }
            }
        }
    }

    printf("%d", cnt);
    return 0;
}