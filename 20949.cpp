#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;
using tiii = tuple<int, int, int>;

int n;
vector<tiii> monitor;

void input() {
	cin >> n;
	monitor.resize(n);
	for (int i = 1; i <= n; i++) {
		auto& [w, d, idx] = monitor[i-1];
		cin >> w >> d;
		idx = i;
	}
}

void sol() {
	stable_sort(ALL(monitor), [](const tiii& a, const tiii& b){
		const auto& [wa, ha, ia] = a;
		const auto& [wb, hb, ib] = b;
		return wa*wa + ha*ha > wb*wb + hb*hb;
	});
	for (auto& [w, d, i] : monitor) {
		cout << i << endl;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}