#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define POW(X) (X) * (X)
using namespace std;

int n;
vector<int> hill;

void input() {
	cin >> n;
	hill.resize(n);
	for(int& x : hill) cin >> x;
	sort(ALL(hill));
}

void sol() {
	int ans = 1000000, mn ,mx, cost;
	for (int i = hill[0]; i < hill[n - 1]; i++) {
		mn = i, mx = i + 17, cost = 0;
		for (int& h : hill) {
			if (h < mn) cost += POW(mn - h);
			else if (h > mx) cost += POW(mx - h);
		}
		ans = min(ans, cost);
	}
	cout << ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}