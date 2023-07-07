#include <stdio.h>
#include <string.h>

int main () {
    int max; // 더 큰 수를 저장하기 위한 변수
    int ten = 1; // 10의 승수
    int num = 0; // 문자열에서 추출한 숫자를 저장하기 위한 변수
    int temp; // 문자열을 숫자로 바꾼 값을 잠시 저장
    char input[8]; // 입력받을 문자열

    fgets(input, 8, stdin); // 입력받는다.
    
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') { // 공백으로 숫자를 구분하므로 공백을 기준으로 한다.
            max = num; // 일단 max에 저장해놓고
            ten = 1; num = 0; // 초기화
        } else {
            temp = input[i] - '0'; // 일단 숫자로 바꾸고
            num += temp * ten; // 10의 n승을 곱하여 더한다
            ten *= 10; // n 1증가
        }
    }
    max = max < num ? num : max; // 여기서의 max : 처음 수, num : 두번째 수. 둘을 비교하여 더 큰 수를 max에 최종적으로 저장
    printf("%d", max);
    return 0;
}