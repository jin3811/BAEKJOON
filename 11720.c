#include <stdio.h>

int main() {
    int sum = 0;
    int a;
    scanf("%d", &a);

    char arr[a];
    scanf("%s", arr);
    
    for (int i=0; i<a; i++) {
        sum += arr[i] - '0';
    }
    printf("%d", sum);
    return 0;
    
}