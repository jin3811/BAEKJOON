#include <stdio.h>

int main () {
    int h,w,n,t; 
    scanf("%d", &t);
    
    while(t--) {
        scanf("%d %d %d", &h, &w, &n);
        printf("%d", n%h == 0 ? h : n%h);
        n = n%h == 0 ? n/h : n/h + 1;
        printf(n < 10 ? "0%d\n" : "%d\n", n);
    }

    return 0;
}