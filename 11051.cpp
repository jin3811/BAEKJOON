#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int comb(int n, int k) {
	if(dp[n][k]) return dp[n][k];
	return dp[n][k] = (comb(n - 1, k - 1) + comb(n - 1, k)) % 10007;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	for(int i = 0; i < 1001; i++) {
		dp[i][i] = dp[i][0] = 1;
	}
	int n, k;
	cin >> n >> k;
	cout << comb(n, k);
}