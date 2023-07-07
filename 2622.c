#include <stdio.h>

int main () {
    int a, b, c, num, end, max;
    int cnt = 0;
    scanf("%d", &num);
    end = (num + 1) / 2;
    for (a = 1; a < end; a++) {
        for (b = 1; b < end; b++) {
            c = num - a - b;
            max = a > b ? (a > c ? a : c) : (b > c ? b : c);
            
            if (max == a) {
                if (b + c > max) cnt++;
            } else if (max == b) {
                if (a + c > max) cnt++;
            } else {
                if (a + b > max) cnt++;
            }
        }
    }
    return 0;
}