#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool group_checker (char *word);

int main (void) {
    int T, result = 0; // 테스트 케이스, 결과값
    char input[101];
    
    scanf("%d", &T);

    while (T--) {
        scanf("%s", input);
        result += group_checker(input) ? 1 : 0;
    }

    printf("%d", result);
    return 0;
}

bool group_checker (char *word) { // 모든 단어가 한번만 등장할 때, 같은 단어가 발견 되었을 때
    bool a = false; // 바깥 반복문을 탈출하기 위한 bool
    bool result = true; // 결과 반환
    char str = 'a'; // 알파벳
    char *pch; // 주소값을 받기 위한 char 포인터
    int cnt; // 알파벳 개수
    int idx; // arr의 요소에 접근하기 위한 인자

    for (int i = 0; i < 26; i++) {
        idx = 0;
        int arr[100]; // 각 알파벳의 주소를 조작한 값을 저장하기 위한 배열 선언 및 초기화
        cnt = 0; // 초기화
        pch = strchr(word, str); // 입력받은 문자열에 알파벳이 있는지 조사

        while(pch != NULL) { // 알파벳이 들어있는 경우
            cnt++;
            arr[idx] = (pch - word); idx++; // 주소값을 word의 n번째로 조작후 저장, 이후 요소값+1
            pch = strchr(pch + 1, str); // 이 알파벳 이후의 문자열에 또 알파벳이 들어있는지 조사
        }

        for (int i = 0; i < cnt-1; i++) { // 알파벳이 그룹을 이루는지 조사
            if (arr[i+1]- arr[i] != 1) { // 그룹이 아닌 경우가 하나라도 발견되면
                result = false; // result를 false로 바꾸고
                a = true; // a를 true로 바꾼다.
            }
        }
        if (a) break;
        str++; // 다음 알파벳으로 바꾼다.
    }
    return result;
}
