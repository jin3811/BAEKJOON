#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
using ll = long long;

ll n, m;
vector<pair<int,int>> fac;

ll fast_pow(ll a, ll b) { // a^b % MOD
	if (b == 1) return a;

	ll tmp = fast_pow(a, b/2) % MOD;
	tmp *= tmp; tmp %= MOD;

	if (b & 1) return (tmp * a) % MOD;
	else return tmp;
}

void sol() {
	ll ans = 1LL;
	for(int i = 2; i * i <= n; i++) {
		fac.emplace_back(i, 0);
		if (n % i == 0) {
			while(n % i == 0) {
				++fac.rbegin()->second;
				n /= i;
			}
		}
	}
	if (n != 1) fac.emplace_back(n, 1);

	for(auto& [p, e] : fac) {
		ll inv = fast_pow(p-1, MOD-2);
		ans *= ((fast_pow(p, e*m+1) - 1) * inv) % MOD;
		ans %= MOD;
	}

	cout << ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cin >> n >> m;
	sol();
}