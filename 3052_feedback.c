#include<stdio.h>

int main(){
    int arr[42] = {0,};
    int n;
    int cnt=0;
    for (int i=0; i<10; i++) {
        scanf("%d", &n);
        arr[n%42]++;
    }
    for (int i = 0; i < 42; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (int i=0; i<42; i++) {
        if (arr[i] != 0) {
            cnt+=1;
        }
    }
    printf("%d", cnt);
    return 0;
}