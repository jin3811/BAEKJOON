#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n;
vector<int> arr;

void input() {
	cin >> n;
	arr.resize(n);
	for(int& x : arr) cin >> x;
}

void sol() {
	vector<int> lis{0}, dp(n, 0);

	for(int i = 0; i < n; i++) {
		if(lis[lis.size() - 1] < arr[i]) {
			lis.push_back(arr[i]);
			dp[i] = lis.size() - 1;
		}
		else {
			int idx = lower_bound(ALL(lis), arr[i]) - lis.begin();
			lis[idx] = arr[i];
			dp[i] = idx;
		}
	}
	cout << lis.size() - 1;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}