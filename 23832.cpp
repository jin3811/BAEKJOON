#include <bits/stdc++.h>
using namespace std;
using ul = uint64_t;

int n;

ul euler_phi(int n) {
	if (n == 1) return (ul)0;
	ul res = n;
	for (ul i = 2; i * i <= n; i++) {
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
	ul res = 0;
	for (int i = 1; i <= n; i++) {
		res += euler_phi(i);
	}
	cout << res;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cin >> n;
	sol();
}