#include <stdio.h>

int which_group (int num, int * group) {
    int idx = 1; // 몇번째 군에 속한지 계산하기 위함
    while (1) {
        if (idx * (idx - 1) / 2 <= num && idx * (idx + 1) / 2 >= num) {
            break;
        } else {
            idx++;
        }
    }
    *group = idx; // 몇번째 군에 있는지
    return num - (idx * (idx - 1) / 2); // 그 군의 몇번째 위치에 있는지
}

int main () {
    int n; // n번째 분수
    int group, loc; 
    scanf("%d", &n);
    loc = which_group(n, &group);
    
    if (group % 2) { // 홀수인 경우
        printf("%d/%d", group + 1 - loc, loc);
    } else { // 짝수인 경우
        printf("%d/%d", loc, group + 1 - loc);
    }

    return 0;
}