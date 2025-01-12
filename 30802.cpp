#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int shirt[6], total, t, p;

void input() {
	cin >> total;
	for(int& x : shirt) cin >> x;
	cin >> t >> p;
}

void sol() {
	int ans = 0;
	for(int& x : shirt) {
		ans += x / t;
		ans += (x % t > 0);
	}
	cout << ans << endl << (total / p) << ' ' << (total % p);
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}