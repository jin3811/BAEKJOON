#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

vector<int> ant;
int n, stick;

void input() {
	cin >> stick >> n;
	ant.resize(n);
	for (int& a : ant) cin >> a;
}

void sol() {
	int mx = 0, mn = 0;
	for (int& a : ant) {
		mx = max(mx, max(stick - a, a));
		mn = max(mn, min(stick - a, a));
	}

	cout << mn << ' ' << mx << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int tc; cin >> tc;
	while (tc--) {
		input();
		sol();
	}
}