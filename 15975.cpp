#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using ul = uint64_t;
using namespace std;

int n;
vector<vector<ul>> v;

void input() {
	ul p, c;

	cin >> n;
	v.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> p >> c;
		v[c - 1].push_back(p);
	}
	for(auto& cl : v) sort(ALL(cl));
}

void sol() {
	ul answer = 0ULL;
	for(auto& colors : v) {
		if (colors.size() <= 1) continue;
		answer += colors[1] - colors[0];
		answer += colors[colors.size() - 1] - colors[colors.size() - 2];

		for (size_t i = 1; i < colors.size() - 1; i++) {
			answer += min(colors[i] - colors[i - 1], colors[i + 1] - colors[i]);
		}
	}
	cout << answer;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol();
}