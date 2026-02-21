#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll sol(ll k) {
	if (k == 1) return 0;
	ll h = 1;
	while(h * 2 < k) h *= 2;
	return !sol(k - h);
}

ll sol2(ll k) {
	if (k <= 64) {
	// 0110100110010110100101100110100110010110011010010110100110010110
	return (7608434000728254870LL >> (64-k)) & 1;
	}
	else {
		ll h = 1;
		while(h * 2 < k) h *= 2;
		return !sol2(k - h);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll k;
	cin >> k;
	cout << sol(k);
}