#include <stdio.h>
#include <string.h>

// 모든 사람이 동일한 캔디를 가지고 있는지 check
// 같으면 return 1
// 다르면 return 0
int check_candys(int *candys, int n)
{
    int ret = 1;
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if (candys[i] != candys[j]) {
                ret = 0;
                break;
            }
        if (!ret) break;
        }
    }
    return ret;
}

// 모든 사람이 짝수개 캔디를 갖도록 조정한다.
void make_even(int *candys, int n)
{
    int i;
    for (i = 0; i < n; i++) 
        candys[i] & 1 ? ++candys[i] : candys[i];
}
// 들고있는 캔디의 반을 우측으로 전달한다.
// Circular Queue 형태로 전달
// 0->1, 1->2, .. (n-1)-->0
void turn_over(int *candys, int n)
{
    int i;
    int tmp1, tmp2; // 더해지기 전의 값을 보존할 변수
    for (i = 0; i < n; i++) {
        candys[i] /= 2;
    }
    tmp1 = candys[0];
    for (i = 0; i < n; i++) {
        if (!i) {
            candys[0] += candys[n-1];
        } else {
            tmp2 = candys[i];
            candys[i] += tmp1;
            tmp1 = tmp2;
        }
    }
}

int main()
{
	int ntest;
	int i, n, candys[10];
	int round;

	scanf("%d", &ntest);
	while (ntest--) {
		scanf("%d", &n);
		// candy[]에 입력을 받는다.
        for (i = 0; i < n; i++) {
            scanf("%d", &candys[i]);
        }
		round = 0;
		// n==1이면 즉시 끝난다.
        if (n == 1) {
            printf("%d\n", round);
        }
        else {
    		while (!check_candys(candys, n)) { // check_candys 모두 같으면 끝난다.
        		// 모든 사람을 짝수개로 만들고
                make_even(candys, n);
                if (check_candys(candys, n)) break;
    			round++;
    			// turn_over 옆사람에게 1/2를 주고
                turn_over(candys, n);
    			// check_candys 모두 같으면 끝난다.
    			// make_even 혹시 홀수개가 있으면 모두 짝수개를 만들고
		    }
		    printf("%d\n", round);
	    }
    }
}