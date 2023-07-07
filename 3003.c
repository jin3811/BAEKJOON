#include <stdio.h>

int main () {
    int set[6] = {1,1,2,2,2,8};
    int user;
    for (int i = 0; i < 6; i++) {
        scanf("%d", &user);
        printf("%d ", set[i] - user);
    }
}