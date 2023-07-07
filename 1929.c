#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool prime_num (int num) {
    int size = floor(sqrt(num));
    bool ret = true;
    
    if (num == 1) {
        ret = !ret;
    } else {
        for (int i = 2; i <= size; i++) {
            if (num % i == 0) {
                ret = !ret;
                break;
            }
        }
    }
    return ret;
}

int main () {
    int m, n;
    scanf("%d%d", &m, &n);

    for (int i = m; i <= n; i++) {
        if (prime_num(i)) printf("%d\n", i);
    }
}