#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000000

void sol(int n) {
	int dp[n][11] = {
		{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	};

	for (int i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][1];
		for (int j = 1; j <= 9; j++) {
			dp[i][j] = ((dp[i - 1][j - 1] % MOD) + (dp[i - 1][j + 1] % MOD)) % MOD;
		}
	}

	int answer = 0;
	for (int i = 0; i <= 9; i++) {
		answer += dp[n - 1][i];
		answer %= MOD;
	}
	cout << answer;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int n;
	cin >> n;
	sol(n);
}