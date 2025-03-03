#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n;
vector<int> a, b;

void input() {
	cin >> n;
	a.resize(n), b.resize(n);
	for(int& x : a) cin >> x;
	for(int& x : b) cin >> x;
	sort(ALL(a)), sort(ALL(b));
}

void sol() {
	int cnt = 0;
	vector<int> ans_a, ans_b;

	for(int& x : b) {
		auto pos = lower_bound(ALL(a), x);

		if (*pos == x) {
			++cnt;
			ans_a.push_back(x), ans_b.push_back(x);
			*pos = -1, x = -1;
		}
	}

	for(int& x : a) {
		if (x != -1) {
			ans_a.push_back(x);
		}
	}

	for(int& x : b) {
		if (x != -1) {
			ans_b.push_back(x);
		}
	}

	cout << cnt << endl;
	for(int& x : ans_a) cout << x << ' ';
	cout << endl;
	for(int& x : ans_b) cout << x << ' ';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol();
}