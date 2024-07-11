#include <bits/stdc++.h>
#define ALL(X) X.rbegin(), X.rend()
#define endl '\n'
using ul = uint64_t;
using namespace std;

int n;
ul total;
vector<ul> money;

void input() {
	cin >> n;
	money.resize(n);
	for(ul& x : money) {
		cin >> x;
		total += x;
	}
	sort(ALL(money));
}

void sol() {
	ul range = 0, tmp = 0, A, B;
	
	for (int i = 0; i < n; i++) {
		range += money[i];
		if (tmp < range * n - (i + 1) * total) {
			A = i + 1;
			B = range;
			tmp = range * n - (i + 1) * total;
		}
	}
	cout << fixed << setprecision(10) << 100. * A / n << endl << 100. * B / total;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}