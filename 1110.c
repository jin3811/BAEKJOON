#include<stdio.h>

int main(){
    int N;
    int temp = -1; 
    int cnt = 0;
    int idx = 0;
    scanf("%d", &N);
    const int first = N;

    while(1){
        if (temp != first) {
            cnt++;
            temp = (int)(N / 10) + (N % 10); // 첫번째: N을 자리수로 분해하여 더한다
            temp = (N % 10)*10 + (temp % 10); // 두번째: 처음 숫자의 1의자리 + 만들어진 숫자의 1의자리 를 로 분해하여 더한다
            N = temp;
            // printf("fisrt: %d, temp: %d, cnt: %d\n", first, temp, cnt);
        } else {
            break; // 탈출   
        }
    }
    printf("%d", cnt);
    return 0;
}