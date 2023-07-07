#include<stdio.h>

int main(){
    char val[10]; // 세 수를 곱한 값을 입력할 문자열, 세자리 자연수의 곱의 최댓값이 9자리수이므로 길이는 10으로 선언
    int a, b, c; // 입력받을 정수
    int rest[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // 숫자의 개수를 저장할 배열(0,1,2....9)
    int temp; // 값을 비교하기 위해 선언한 int형 변수
    int i; // 반복문을 위한 인자

    scanf("%d%d%d", &a, &b, &c); // a, b, c 입력 받는다.
    sprintf(val, "%d", a*b*c); // 세 수의 곱을 문자열로 바꾼다.
    
    for (i = 0; i < 10; i++) {
        temp = val[i] - '0'; // 단일문자로 된 문자를 정수로 바꾼다.
        rest[temp]++;
    }
    for (i = 0; i < 10; i++){
        printf("%d\n", rest[i]);
    }
    return 0;
}