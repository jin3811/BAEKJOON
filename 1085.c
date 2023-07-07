#include <stdio.h>

int main () {
    int x,y,w,h;
    int resultx, resulty;

    scanf("%d %d %d %d", &x, &y, &w, &h);

    resultx = x < w - x ? x : w - x;
    resulty = y < h - y ? y : h - y;
    
    printf("%d", resultx < resulty ? resultx : resulty);
    return 0;
}