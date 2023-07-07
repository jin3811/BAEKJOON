#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;
using pii = pair<int, int>;

int w, h;
pii x;
vector<pii> v;
map<int, int> rotate_table = {{1, 4}, {4, 2}, {2, 3}, {3, 1}};

void area_rotate() {
	for (auto& p : v) {
		if ((p.first - 1) / 2 == 1) {
			p.second = h - p.second;
		}
		p.first = rotate_table[p.first];
	}
	
	if ((x.first - 1) / 2 == 1) {
		x.second = h - x.second;
	}
	x.first = rotate_table[x.first];
	swap(w, h);
}

void input() {
	int n;
	cin >> w >> h >> n;
	v.resize(n);
	for (auto& p : v) cin >> p.first >> p.second;
	cin >> x.first >> x.second;
	while(x.first != 2) area_rotate();
}

void sol() {
	int total = 0;
	for (const auto& p : v) {
		if (p.first == 1) {
			total += h + min(x.second + p.second, 2 * w - x.second - p.second);
		}
		else if (p.first == 2) {
			total += abs(p.second - x.second);
		}
		else if (p.first == 3) {
			total += x.second + h - p.second;
		}
		else {
			total += w - x.second + h - p.second;
		}
	}
	cout << total;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}