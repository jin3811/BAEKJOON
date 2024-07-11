#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int t, n;
	int dp[12] = {0, 1, 2, 4};

	for (int i = 4; i < 12; i++) {
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	}
	
	cin >> t;
	while(t--){
		cin >> n;
		cout << dp[n] << '\n';
	}
}