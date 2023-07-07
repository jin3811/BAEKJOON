#include <stdio.h>

int main() {
    int h, w; // 층수, 호수
    int T; // 테스트 케이스
    int arr[15][15];

    for (int i = 0; i < 15; i++) { // 0층, 0호, 1호 설정
        arr[0][i] = i;
        arr[i][0] = 0; // 0호는 존재하지 않으니 0으로 초기화
    }
    for (int i = 1; i < 15; i++) { // i층
        for (int j = 1; j < 15; j++) { // j호
            arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
        }
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &h, &w);
        printf("%d\n", arr[h][w]);
    }
    
	return 0;
}