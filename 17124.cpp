#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n, m;
vector<int> a, b;

void input() {
	cin >> n >> m;
	a.resize(n), b.resize(m);
	for(int& x : a) cin >> x;
	for(int& x : b) cin >> x;
	sort(ALL(b));
}

void sol() {
	long long ans = 0;
	int dl, dr;
	
	for(int& x : a) {
		auto iter = lower_bound(ALL(b), x);
		if (iter == b.begin()) {
			ans += *iter;
		}
		else if (iter == b.end()) {
			ans += *(--iter);
		}
		else {
			dl = abs(x - *(iter-1)), dr = abs(*iter - x);
			ans += dl <= dr ? *(iter - 1) : *iter;
		}
	}

	cout << ans << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int tc; cin >> tc;
	while(tc--) {
		input();
		sol();
	}
}