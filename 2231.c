#include <stdio.h>
#include <math.h>

int main () {
    int n, a = 1, cnt = 1; // 입력받은 셀프넘버, 생성자
    int check = 0; // 만들어진 셀프넘버, n과 같은지 체크하기 위함
    int is_true = 0; // 존재하는지 체크하기 위한 변수

    scanf("%d", &n);
    // n = 216;
    while (cnt<=n) {
        a = cnt;
        check = cnt;
        for (int i = 0; i <= floor(log10(cnt)+1); i++) {
            check += a % 10;
            a /= 10;
        }
        // printf("%d, %d\n", cnt, check);
        if(check == n) {
            is_true = 1;
            break;
            }
        cnt++;
    }
    printf("%d", is_true ? cnt : 0);
    return 0;
}