#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;
using pii = pair<int, int>;

vector<pii> rooms;
int n;

void input() {
	cin >> n;
	rooms.resize(n);
	for (auto& [s, e] : rooms) cin >> e >> s;
	sort(ALL(rooms));
}

void sol() {
	int cur = rooms[0].first, res = 1;

	for (int i = 1; i < n; i++) {
		auto& [e, s] = rooms[i];
		if (cur <= s) {
			res++;
			cur = e;
		}
	}
	cout << res;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}