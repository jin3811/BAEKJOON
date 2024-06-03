#include <iostream>
#define mod 10007
using namespace std;

int n;

void sol() {
	int dp[n + 1] = {1, 1};
	for (int i = 2; i <= n; i++) {
		dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % mod;
	}
	cout << dp[n];
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cin >> n;
	sol();
}