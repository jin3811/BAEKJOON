#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int m, n, x, y;

int gcd(int a, int b) {
	return !b ? a : gcd(b, a%b);
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

void sol() {
	int maxYear = lcm(m, n);
	int tmp_y = y;

	for(; x <= maxYear; x += m) {
		int tmp = x % n;
		if (tmp == 0) {
			tmp = n;
		}
		
		if (tmp == y) {
			cout << x << endl;
			return;
		}
	}
	cout << -1 << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> m >> n >> x >> y;
		sol();
	}
}