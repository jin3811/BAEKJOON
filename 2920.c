#include <stdio.h>

int main () {
    int arr[8];
    int a = 0;
    for (int i = 0; i < 8; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 7; i++) {
        if (arr[i] - arr[i+1] == 1) {
            a--;
        } else if (arr[i] - arr[i+1] == -1) {
            a++;
        }
    }
    if (a == 7) {
        printf("ascending");
    } else if (a == -7) {
        printf("descending");
    } else {
        printf("mixed");
    }
    
    return 0;
}