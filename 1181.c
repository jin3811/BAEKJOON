#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 문자열로 해결하려 했으나 자꾸 안돼서 그냥 구조체 선언
typedef struct { 
    char word[51];
    int len;
}String;

// compare함수 : 원하는 비교연산을 통해 -1, 0 ,1을 반환한다. qsort에서 쓰는 인자는 const void 포인터.
int compare (const void * p1, const void * p2) { 
    String * str1 = (String *)p1; 
    String * str2 = (String *)p2;
    
    if (str1->len < str2->len) return -1; // 길이에 따라 반환
    else if (str1->len > str2->len) return 1;
    else return strcmp(str1->word, str2->word); 

}

int main () {
    int n;
    scanf("%d", &n);
    String * strArr = (String *)malloc(sizeof(String) * n); // 동적 할당, 변수가 배열 길이로 들어가는 것을 방지
    
    for (int i = 0; i < n; i++) {
        while (getchar() != '\n'); // 입력받기 전에 입력버퍼를 비운다.
        scanf("%s", strArr[i].word); // 입력받고
        strArr[i].len = strlen(strArr[i].word); // strlen함수로 길이 입력
    }

    qsort(strArr, n, sizeof(String), compare); // quick sort (in stdlib.h)
    
    for (int i = 0; i < n-1; i++) { // 중복 제거
        for (int j = i + 1; j < n; j++) {
            if (!strcmp(strArr[i].word, strArr[j].word)) { // 중복이 발견되면
                strcpy(strArr[j].word, "\0"); // 널문자로 바꿔쓰고
                strArr[j].len = 0; // 길이를 0으로
            }            
        }
    }

    for (int i = 0; i < n; i++) { // 출력
        if(strArr[i].len) printf("%s\n", strArr[i].word);
    }
}