/**
 * boj/2758
 * 
 * n을 줄여가며, 각 자리수의 최댓값까지 탐색한다. n = 3을 기준으로 하고, 맨 왼쪽부터 n번째 자리라고 하자.
 * 맨 왼쪽 자릿수의 최댓값은 m / (2 ^ (n-1))이 될 것이다. 오른쪽 숫자가 2배가 되어야 하면서, 모든 숫자가 m 이하여야 하기 때문이다.
 * 간단히 n = 4, m = 17이라고 하면 왼쪽부터 올수 있는 최댓값은 2, 4, 8, 17이 될 것이다. 각각 17/2^3, 17/2^2, 17/2^1, 17/2^0이다.
 * 
 * 재귀를 돌면서 각 자리의 최댓값까지 순회해주며 개수를 센다. 이때 중복되는 경우가 발생할 수 있다.
 * 
 *  위 예제를 그대로 활용해봐도 1 2 8 16, 2 4 8 16에서 8 이후로 반복된다. 각 숫자가 몇번째에 쓰였을 때, 그 이후로 등장할 수 있는 숫자가 몇개인지 메모이제이션하면서 연산을 줄이면 된다.
 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

int n, m;
ll memo[10][2001];

ll sol(int cnt, int cur) {
	if (memo[cnt][cur] != -1) {
		return memo[cnt][cur];
	}

	if (cnt == 0) {
		return m - cur + 1;
	}

	memo[cnt][cur] = 0;
	for(int i = cur; i <= m / (1 << cnt); i++) {
		memo[cnt][cur] += sol(cnt - 1, i * 2);
	}
	return memo[cnt][cur];
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int tc; cin >> tc;
	
	while(tc--) {
		cin >> n >> m;
		for(auto& row : memo) memset(row, 0xff, sizeof(ll)*2001);
		cout << sol(n - 1, 1) << endl;
	}
}