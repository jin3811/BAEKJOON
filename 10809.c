#include <stdio.h>

int main(){
    char S[100]; // 입력받을 문자열
    int ascii; // 알파벳을 아스키코드를 이용한 숫자로 저장할 변수
    int alpha[26] = {0,}; // 알파벳 위치에 대응하는 배열
    int idx = 0; // 반복 인자
    int first; // 맨 첫글자를 저장할 변수

    scanf("%s", S);

    while (S[idx] != '\0'){
        ascii = S[idx] - 'a'; // 알파벳을 숫자로 변환한다   
        first = idx == 0 ? ascii : first; // 맨 처음에 위치하는 알파벳

        alpha[ascii] = alpha[ascii] == 0 ? idx : alpha[ascii]; // 알파벳 위치에 대응하는 요소에 맨 처음 위치 저장
        if (ascii == first) { // 맨 처음 등장하는 단어가 그 다음 위치의 숫자로 바뀔 수 있으므로 0으로 수정하여 이를 방지한다
            alpha[ascii] = 0;
        }
        idx++;
    }

    for (int i=0; i<26; i++) {
        if (alpha[i] == 0 && i != first) { // 요소의 값이 0이면서, 동시에 첫글자가 아닌 경우
            printf("-1 ");
        } else {
            printf("%d ", alpha[i]);
        }
    }
}
