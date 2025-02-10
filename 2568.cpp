#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;
using pii = pair<int,int>;

int n;
vector<pair<int,int>> wire;

void input() {
	cin >> n;
	wire.resize(n);
	for(auto& [a, b] : wire) cin >> a >> b;
	sort(ALL(wire));
}

void sol() {
	vector<int> lis_length(1), dp(n);
	deque<int> lis;

	for(int i = 0; i < n; i++) {
		int con = wire[i].second;

		if(lis_length[lis_length.size() - 1] < con) {
			lis_length.push_back(con);
			dp[i] = lis_length.size() - 1;
		}
		else {
			int idx = lower_bound(ALL(lis_length), con) - lis_length.begin();
			lis_length[idx] = con;
			dp[i] = idx;
		}
	}

	int len = lis_length.size() - 1;
	cout << n - len << endl;

	for(int i = n - 1; i >= 0 && len; --i) {
		if (dp[i] == len) {
			--len;
			lis.push_front(wire[i].second);
		}
	}

	for(auto& [a, b] : wire) {
		auto p = lower_bound(ALL(lis), b);
		if (*p != b) {
			cout << a << endl;
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol();
}