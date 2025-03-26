#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int memo[1001][1001];

int sol(int n, int m) {
	if (n == 1 || m == 1) return 1;
	if (memo[n][m] != -1) return memo[n][m];
	return memo[n][m] = ((((sol(n - 1, m - 1) % MOD) + (sol(n, m - 1) % MOD)) % MOD) + (sol(n - 1, m) % MOD)) % MOD;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	memset(memo, 0xff, sizeof(int)*1001*1001);
	int n, m; cin >> n >> m;
	cout << sol(n, m);
}