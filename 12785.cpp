#include <bits/stdc++.h>
using namespace std;
#define mod 1000007

int w, h, x, y;

int comb(int a, int b) { // a+bCa % mod
	int n = a + b;
	int r = min(a, b);

	int result = 1;
	int temp = 1;

	for (int i = n; i > n - r; i--) {
		result *= i;
		result /= temp++;
		result %= mod;
	}
	return result % mod;
}	

int sol() {
	int h2t = comb(x - 1, y - 1);
	int t2s = comb(w - x, h - y);
	return (h2t * t2s) % mod;
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> w >> h >> x >> y;
	cout << sol();
}