#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 1000000007LL

int m;
vector<pair<ll, ll>> dice;

void input() {
	cin >> m;
	dice.resize(m);
	for(auto& [n, s] : dice) cin >> n >> s;
}

tuple<ll, ll, ll> xGCD(ll a, ll b) {
	if (b == 0) {
		return {a, 1, 0};
	}
	auto[g, x, y] = xGCD(b, a%b);
	return {g, y, x-(a/b)*y};
}

void sol1() {
	ll ans = 0LL;

	for(auto& [n, s] : dice) {
		auto [g, inv, y] = xGCD(n, MOD);
		ans += (s * ((inv + MOD) % MOD)) % MOD;
		ans %= MOD;
	}
	cout << ans;
}

ll fast_square(ll a, ll b) {
	if (b == 0) return 1;
	if (b == 1) return a;

	ll tmp = fast_square(a, b/2) % MOD;

	if (b % 2) return (a * ((tmp * tmp) % MOD)) % MOD;
	else return (tmp * tmp) % MOD;
}

void sol2() {
	ll ans = 0LL;

	for(auto& [n, s] : dice) {
		ll inv = fast_square(n, MOD - 2);
		ans += (s * inv) % MOD;
		ans %= MOD;
	}

	cout << ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input();
	// sol1();
	sol2();
}