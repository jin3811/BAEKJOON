#include <stdio.h>
#include <string.h>

int change (const char a) {
    if (a == 'A'|| a == 'B'|| a == 'C') return 2;
    if (a == 'D'|| a == 'E'|| a == 'F') return 3;
    if (a == 'G'|| a == 'H'|| a == 'I') return 4;
    if (a == 'J'|| a == 'K'|| a == 'L') return 5;
    if (a == 'M'|| a == 'N'|| a == 'O') return 6;
    if (a == 'P'|| a == 'Q'|| a == 'R'|| a == 'S') return 7;
    if (a == 'T'|| a == 'U'|| a == 'V') return 8;
    if (a == 'W'|| a == 'X'|| a == 'Y'|| a == 'Z') return 9;
}

int main () {
    char a[15];
    int time = 0;
    scanf("%s", a);

    for (int i = 0; i < strlen(a); i++) {
        time += change(a[i]) + 1;
    }
    
    printf("%d", time);
    return 0;
}