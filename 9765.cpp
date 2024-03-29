#include <bits/stdc++.h>
using ll = uint64_t;
using namespace std;

ll c[7], x[9];

ll gcd(int a, int b){
	return b ? gcd(b, a%b) : a;
}

void sol() {
	ll tmp = gcd(c[1], c[5]);
	x[1] = c[1] / tmp;
	x[3] = c[5] / tmp;
	x[2] = c[1] / x[1];

	tmp = gcd(c[3], c[6]);
	x[7] = c[3] / tmp;
	x[5] = c[6] / tmp;
	x[6] = c[6] / x[5];

	for (int i = 1; i < 9; i++) {
		if (x[i]) cout << x[i] << ' ';
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	for (int i = 1; i < 7; i++) cin >> c[i];
	sol();
}