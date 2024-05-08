#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using tl3 = tuple<ll, ll, ll>;

int x[3], p[3]; // x : a, p : m

void input() {
	for(int& i : p) cin >> i;
	for(int& i : x) cin >> i;
}

tl3 xGCD(ll a, ll b) {
	if (b == 0) {
		return {a, 1, 0};
	}
	auto[g, x, y] = xGCD(b, a%b);
	return {g, y, x-(a/b)*y};
}

void sol() {
	ll a1 = x[0], m1 = p[0];
	
	for (int i = 1; i < 3; i++) {
		ll a2 = x[i], m2 = p[i];
		auto[g, x, _] = xGCD(m1, m2);

		if ((a2 - a1) % g) {
			cout << -1;
			return;
		}
		
		ll k1 = x * (a2 - a1) / g;
		a1 += m1 * k1;
		m1 = lcm(m1, m2);
		a1 %= m1;
	}
	cout << (a1 + m1) % m1;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}