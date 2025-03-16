#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;

int n, m;
vector<int> v;

void input() {
	cin >> n >> m;
	v.resize(n);
	for(int& x : v) cin >> x;
	sort(ALL(v));
}

void sol() {
	int l = 0, r = 0, answer = INT32_MAX, diff = 0;
	while(l <= r) {
		if (diff >= m) diff = v[r] - v[++l];
		else if (r == n - 1 && diff < m) break;
		else diff = v[++r] - v[l];
		if (diff >= m) answer = min(answer, diff);
	}
	cout << answer;
}

void sol2() {
	int answer = INT32_MAX;
	for(auto iter = v.begin(); iter != v.end(); ++iter) {
		auto k = lower_bound(iter, v.end(), *iter+m);
		if(k == v.end()) break;
		answer = min(*k-*iter, answer);
	}
	cout << answer;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol();
}