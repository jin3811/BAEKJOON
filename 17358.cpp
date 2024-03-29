#include <bits/stdc++.h>
using ul = uint64_t;
using namespace std;
#define MOD ((int)1e9+7)

int n;
vector<ul> dp;

void init_dp() {
	dp.resize(n + 2, 0);
	dp[0] = dp[2] = 1;
}

void sol() {
	init_dp();

	if (!dp[n]) {
		for (int i = 4; i <= n; i += 2) {
			dp[i] = (dp[i - 2] % MOD + (dp[i - 4] % MOD * ((i - 2L) * (i - 3)) % MOD) % MOD) % MOD;
		}
	}
	
	cout << dp[n];
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cin >> n;
	sol();
}