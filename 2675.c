#include <stdio.h>
// #include <string.h>

int main(){
    int T, R; // 테스트 케이스, 반복 횟수
    char S[21]; // 입력받는 문자열
    // char P[161]; // 내보낼 문자열
    int idx;

    scanf("%d", &T);

    for (int i=0; i<T; i++) {
        scanf("%d %s", &R, S);
        char P[161] = "";
        idx = 0;
        // printf("%d %s\n", R, S);

        while (S[idx] != '\0') {
            // char *temp = &S[idx];
            // printf("%c\n", S[idx]);
            // for (int i = 0; i < R; i++){
            //     strcat(P, S);
            //     printf("cat: %s\n",P);
            // }
            for (int i=0; i<R; i++) {
                P[idx*R+i] = S[idx];
            }
            idx++;
        }
        printf("%s\n", P);
    }
    return 0;
}