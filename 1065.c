#include <stdio.h>

int hansu (int num) {
    int cnt = 0;
    int a, b, c;

    if (num < 100) { // 100미만의 자연수는 무조건 한수
        cnt = num;
    } else if (num >= 100 && num <= 110){// 100 ~ 110사이에 한수는 없다.
        cnt += 99;
    } else {
        cnt += 99;
        for (int i = 111; i <= num; i++) { 
            if (i == 1000) { // 1000은 한수가 아니기 때문에 따지지 않는다.
                break;
            }
            a = i / 100;
            b = (i / 10) % 10;
            c = i % 10;

            if ((a - b) == (b - c)) {
                cnt++;
            }
        }
    }

    return cnt;
}

int main(){
    int N;

    scanf("%d", &N);
    printf("%d", hansu(N));

    return 0;
}