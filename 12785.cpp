#include <bits/stdc++.h>
using namespace std;
#define mod 1000007

int w, h, x, y;

int memo[500][500];

int comb(int n, int r) {
    if (memo[n][r]) {
		return memo[n][r] % mod;
	}
    else{
        memo[n][r] = ((comb(n - 1, r - 1) % mod) + (comb(n - 1, r) % mod)) % mod;
        return memo[n][r];
    }
}
void sol() {
	for(int i = 0; i < 500; i++) {
        memo[i][0] = memo[i][i] = 1;
    }
	int t2s = comb(w + h - x - y, min(w - x, h - y));
	int h2t = comb(x + y - 2, min(x - 1, y - 1));
	long long ans = (1LL * h2t * t2s) % mod;
	cout << ans;
}

int main () {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> w >> h >> x >> y;
	sol();
}