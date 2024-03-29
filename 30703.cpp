#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a, b, x;

void input() {
	cin >> n;
	a.resize(n); b.resize(n); x.resize(n);
	for (int& x : a) cin >> x;
	for (int& x : b) cin >> x;
	for (int& x : x) cin >> x;
}

void sol() {
	for (int i = 0; i < n; i++) {
		if (abs(a[i] - b[i]) % x[i] != 0) {
			cout << -1;
			return;
		}
	}
	
	vector<int> count(n);
	for (int i = 0; i < n; i++) {
		count[i] = abs(a[i] - b[i]) / x[i];
	}

	int tmp = count[0] % 2;
	int answer = count[0];
	for (int i = 1; i < n; i++) {
		if (tmp != count[i] % 2) {
			cout << -1;
			return;
		}
		answer = max(answer, count[i]);
	}
	cout << answer;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}