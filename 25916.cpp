#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n, m;
vector<int> holes;

void input() {
	cin >> n >> m;
	holes.resize(n);
	for (int& hole : holes) cin >> hole;
}

void sol() {
	int l = 0, r = 0;
	int cur = 0;
	int ans = 0;

	while(l <= r && r < n) {
		if (cur <= m) {
			ans = max(ans, cur);
			cur += holes[r++];
		}
		else {
			cur -= holes[l++];
		}
	}
	if (cur <= m) ans = max(ans, cur);
	cout << ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}