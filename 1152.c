#include <stdio.h>
#include <string.h>

int main () {
    char a[1000001]; // 받을 문자열
    int word = 0; // 단어의 개수

    // scanf("%[^\n]s", a);
    // gets(a);
    fgets(a, 1000001, stdin);

    for (int i = 0; i < strlen(a); i++) {
        if (a[i] == ' ') word++;
    }
    if (a[0] == ' ') word--;
    if (a[strlen(a)-2] == ' ') word--;

    printf("%d",word+1); // 공백이 n개라면 단어는 n+1개
    return 0;
}
