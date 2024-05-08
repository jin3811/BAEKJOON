#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
#define MOD 987654321

int n;

void sol() {
	ll dp[100010][10] = {0L};
	ll res = 0;

	for(int i = 1; i < 10; i++) dp[1][i] = 1L;
	
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < 10; j++) {
			for (int k = max(1, j - 2); k <= min(9, j + 2); k++) {
				dp[i + 1][j] += dp[i][k] % MOD;
				dp[i + 1][j] %= MOD;
			}
		}
	}

	for (int i = 1; i <= 10; i++) {
		res += dp[n][i] % MOD;
		res %= MOD;
	}
	cout << res;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cin >> n;
	sol();
}