#include <bits/stdc++.h>
using namespace std;
#define LEN 510

int n, tri[LEN][LEN], dp[LEN][LEN];

void input() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= i; j++) {
			cin >> tri[i][j];
		}
	}
	dp[0][0] = tri[0][0];
}

void sol() {
	for(int i = 1; i < n; i++) {
		for(int j = 0; j <= i; j++) {
			if (j) dp[i][j] = max(dp[i][j], tri[i][j] + max(dp[i-1][j-1], dp[i-1][j]));
			else dp[i][j] = max(dp[i][j], tri[i][j] + dp[i-1][j]);
		}
	}
	cout << *max_element(dp[n-1], dp[n-1] + n);
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}