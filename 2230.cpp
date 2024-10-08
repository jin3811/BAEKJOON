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
	while(1) {
		if (diff > m) diff = v[r] - v[++l];
		else if (r == n - 1 && diff <= m) break;
		else diff = v[++r] - v[l];
		if (diff >= m) answer = min(answer, diff);
	}
	cout << answer;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol();
}