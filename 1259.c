#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool palindrome_num (char *num, int len) {
    int size = (len + 1) / 2;
    bool ret = true;

    for (int i = 0; i < size; i++) {
        if (num[i] != num[len-1-i]) {
            ret = !ret;
            break;
        }
    }
    return ret;
}

int main () {
    char a[6];

    while (1) {
        scanf("%s", a);
        if (!strcmp(a, "0")) break;
        printf(palindrome_num(a, strlen(a)) ? "yes\n" : "no\n");
    }
    
    return 0;
}
