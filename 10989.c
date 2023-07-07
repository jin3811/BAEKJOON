#include <stdio.h>
#define SIZE 10000

int main () {
    int count[SIZE] = {0};
    int t, input;

    scanf("%d", &t);
    while(t--) {
        scanf("%d", &input);
        count[input-1]++;
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < count[i]; j++) {
            printf("%d\n", i+1);
        }
    }
}