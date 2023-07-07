#include <stdio.h>

int powi (int a, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= a;
    }
    return result;
}

int main () {
    int T;
    int x1, y1, r1, x2, y2, r2;
    int distance;
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

        if (x1 == x2 && y1 == y2) { // 동심원
            printf(r1 == r2 ? "-1\n" : "0\n"); // 반지름이 같으면 교점은 무한개, 다르면 0;
        } else {
            distance = powi(x2 - x1, 2) + powi(y2 - y1, 2); // 중심간 거리의 제곱값을 잰다.

            if (powi(r1 - r2, 2) < distance && distance < powi(r1 + r2, 2)) { // 두 점에서 만나는 경우
                printf("2\n");
            } else if (distance == powi(r1 + r2, 2) || distance == powi(r1 - r2, 2)) { // 한 점에서 접하는 경우
                printf("1\n");
            } else { // 만나지 않는 경우, 교점은 없다.
                printf("0\n");
            }
        }
    }
    return 0;
}