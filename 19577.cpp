#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;
using ul = uint64_t;

int n;

ul euler_phi(int n) {
	ul res = n;

	for (int i = 2; i * i <= n; i++) {
		if (n % i) continue;

		res /= i;
		res *= (i - 1);
		while (n % i == 0) n /= i;
	}
	if (n != 1) {
		res /= n;
		res *= (n - 1);
	}

	return res;
}

void sol() {
	int tmp;
	vector<int> factor;

	for (int i = 1; i * i <= n; i++) {
		if (n % i) continue;
		factor.push_back(i);
		if (i != n / i) factor.push_back(n / i);
	}
	sort(ALL(factor));

	for (int& x : factor) {
		if (euler_phi(x) == n / x) {
			cout << x;
			return;
		}
	}
	cout << -1;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cin >> n;
	sol();
}