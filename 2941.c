#include <stdio.h>
#include <string.h>

int main () {
    char a[101];
    int word = 0;
    int i = 0;
    scanf("%s", a);

    while (i < strlen(a)) {
        if (a[i] == 'c' && a[i+1] == '=') {
            i += 2;
        } else if (a[i] == 'c' && a[i+1] == '-') {
            i += 2;
        } else if (a[i] == 'd' && a[i+1] == 'z' && a[i+2] == '=') {
            i += 3;
        } else if (a[i] == 'd' && a[i+1] == '-') {
            i += 2;
        } else if (a[i] == 'l' && a[i+1] == 'j') {
            i += 2;
        } else if (a[i] == 'n' && a[i+1] == 'j') {
            i += 2;
        } else if (a[i] == 's' && a[i+1] == '=') {
            i += 2;
        } else if (a[i] == 'z' && a[i+1] == '=') {
            i += 2;
        } else {
            i++;
        }
        word++;
    }
    
    printf("%d", word);
    return 0;
}