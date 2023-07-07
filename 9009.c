// 1학기 프로그래밍랩 
// 4주
// Lab4-ACM : 양의 정수를 최소 개수의 피보나치 수열의 합으로 구하기
// 100 = 3 + 8 + 89
// 입력 100
// 출력 3 8 89 (작은수에서 큰 수 순으로)

#include <stdio.h>
// f<=n 인 fibonacci 최대값 f 를 구해서 return 한다
// recursive 로 작성하면 너무 시간이 오래 걸리기 때문에
// iterative 방식으로 구현하여야 함 (for문 하나로 해결)
int find_max_fibo(int n)
{
	int a1 = 0, a2 = 1;
	int fibo = 1;
	while (a1 + a2 <= n) {
		fibo = a1 + a2;
		a1 = a2;
		a2 = fibo;
	}
	return fibo;
}

// n 이 주어지면
// n==1 이면 1을 출력하고 return -- 1
// f <= n 인 피보나치 최대값 f를 찾고 -- 2
// f==n 이면 f를 출력 하고 return -- 3
// (n-f)>0 이면 n=(n-f) 에 대해 다시 피보나치 조합을 재귀함수로 찾는다 -- 4
void find_fibos(int n)
{
	if (n == 1) { // -- 1
		printf("1 ");
		// return 1;
	}
	else {
		int f = find_max_fibo(n); // -- 2
		if (f == n) { // -- 3
			printf("%d ", f);
			return;
		}
		else if (n - f > 0) { // -- 4
			// printf("--%d ", f);
			find_fibos(n - f);
		}
        printf("%d ", f);
	}
}

int main()
{
	int n_tests;
	int n, max_fibo;
	scanf("%d", &n_tests);
	while (n_tests--) {
		scanf("%d", &n);
		find_fibos(n);
		printf("\n");
	}

}