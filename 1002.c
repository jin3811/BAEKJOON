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

        if (x1 == x2 && y1 == y2) { // ���ɿ�
            printf(r1 == r2 ? "-1\n" : "0\n"); // �������� ������ ������ ���Ѱ�, �ٸ��� 0;
        } else {
            distance = powi(x2 - x1, 2) + powi(y2 - y1, 2); // �߽ɰ� �Ÿ��� �������� ���.

            if (powi(r1 - r2, 2) < distance && distance < powi(r1 + r2, 2)) { // �� ������ ������ ���
                printf("2\n");
            } else if (distance == powi(r1 + r2, 2) || distance == powi(r1 - r2, 2)) { // �� ������ ���ϴ� ���
                printf("1\n");
            } else { // ������ �ʴ� ���, ������ ����.
                printf("0\n");
            }
        }
    }
    return 0;
}