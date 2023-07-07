#include <stdio.h>

int main () {
    int alpha[26] = {0,}; // 입력받은 문자열에 있는 알파벳의 개수
    int ascii, idx = 0, temp = -1, max = 0, loc; // 아스키코드, 반복인자, 최댓값의 개수, 많이 나온 알파벳의 위치
    char input[1000001]; // 입력받을 문자열
    
    scanf("%s", input);

    while (input[idx] != '\0') { // 알파벳이 나온 횟수를 기록
        ascii = input[idx]; // 알파벳의 아스키코드 저장
        ascii = ascii <= 90 ? ascii - 65 : ascii - 97; // 대소문자에 따라 식을 다르게 조작
        alpha[ascii]++; // 해당하는 위치의 요소를 1 더한다.
        idx++; 
    }

    for (int i = 0; i < 26; i++) {
        if (temp < alpha[i]) { // 최댓값이 발견되면
            temp = alpha[i]; // 바꾸고
            loc = i; // 위치를 기록한 후에
            max = 0; // 같은 개수의 것들을 초기화
        } else if (temp == alpha[i] && alpha[i] != 0) { // 같은 개수인 경우
            max++; // 1 더한다
        }
    }
    // for (int i = 0; i < 26; i++) { // 디버깅
    //     printf("%d ", alpha[i]);    
    // }
    
    // printf("\nmax:%d\ntemp:%d\n", max, temp);

    if (max == 0) { // 출력
        printf("%c", loc + 65); // 대문자로 출력하기 위해 아스키코드를 조작한다
    } else {
        printf("?"); // max가 0이 아니라는 건 중복되는게 있다는 뜻
    }
    return 0;
}
