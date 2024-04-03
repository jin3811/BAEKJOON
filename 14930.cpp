#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;
using pii = pair<int, int>;

int n, t;
vector<pii> pos;
pii R;

void input() {
	cin >> n >> t;
	pos.resize(n);
	for(auto& [p, v] : pos) cin >> p >> v;
	R = pos[0];
	sort(ALL(pos));
}

void sol() {
	vector<long long> after_t(n);
	auto redBead = distance(pos.begin(), find(ALL(pos), R));

	for (int i = 0; i < n; i++) {
		auto& [p, v] = pos[i];
		after_t[i] = p + 1L * v * t;
	}

	sort(ALL(after_t));
	
	cout << after_t[redBead];
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}