#include <stdio.h>
// #include <string.h>

int main(){
    int T, R; // �׽�Ʈ ���̽�, �ݺ� Ƚ��
    char S[21]; // �Է¹޴� ���ڿ�
    // char P[161]; // ������ ���ڿ�
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