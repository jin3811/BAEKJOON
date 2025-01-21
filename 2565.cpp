#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n;
vector<pair<int,int>> wire;

void input() {
	cin >> n;
	wire.resize(n);
	for(auto& [a, b] : wire) cin >> a >> b;
	sort(ALL(wire));
}

void sol() {
	int con;
	vector<int> lis{0}, dp(n, 0);

	for(int i = 0; i < n; i++) {
		con = wire[i].second;
		if(lis[lis.size() - 1] < con) {
			lis.push_back(con);
			dp[i] = lis.size() - 1;
		}
		else {
			int idx = lower_bound(ALL(lis), con) - lis.begin();
			lis[idx] = con;
			dp[i] = idx;
		}
	}
	cout << n - lis.size() + 1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol();
}