#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;

int n, m;
vector<pair<int,int>> v;

void input() {
	int l, r;
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >> l >> r;
		v.push_back({l, i});
		v.push_back({r, i});
	}
	sort(ALL(v));
}

void sol() {
	while(n > 2 * m) n -= 2 * m;
	cout << v[n - 1].second;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}