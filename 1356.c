#include <stdio.h>
#include <string.h>

int main () {
    char ch[11];
    int len;
    int n1, n2;
    int i, j;
    scanf("%s", ch);
    len = strlen(ch);
    if (len == 1) {
        printf("NO");
    } else {
        for (i = 0; i < len-1; i++) {
            n1 = 1; n2 = 1;
            for (j = 0; j <= i; j++)
                n1 *= ch[j] - '0';
            for (j; j < len; j++)
                n2 *= ch[j] - '0';
            if (n1 == n2) break;
        }
        printf(n1 == n2 ? "YES" : "NO");
    }
    return 0;
}