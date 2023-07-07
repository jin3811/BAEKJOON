#include <stdio.h>

int main () {
    int t;
    int max = 0;
    int idx = 2;
    int temp = 1;

    scanf("%d", &t);
    int arr[t];
    
    for (int i = 0; i < t; i++) {
        scanf("%d", &arr[i]);
        max = max < arr[i] ? arr[i] : max;
    }

    while (idx < max) {
        temp = 1;
        for (int i = 0; i < t - 1; i++) {
            if (arr[i] % idx != arr[i+1] % idx ){
                temp = 0;
                break;
            }
        }
        if (temp == 1) printf("%d ", idx);
        idx++;
    }
    
    return 0;
}