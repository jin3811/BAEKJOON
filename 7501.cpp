#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;

using ll = int64_t;
using ul = uint64_t;

struct Random {
	mt19937 rd;
	Random(int seed = (unsigned)chrono::steady_clock::now().time_since_epoch().count()) : rd(seed) {}
	template<typename T = int>
	T GetInt(T l = 0, T r = 32767) {
		return uniform_int_distribution<T>(l, r)(rd);
	}
	double GetDouble(double l = 0, double r = 1) {
		return uniform_real_distribution<double>(l, r)(rd);
	}
} Rand;

struct MillerRabin {
	ll Mul(ll x, ll y, ll MOD) {
		ll ret = x * y - MOD * ul(1.L / MOD * x * y);
		return ret + MOD * (ret < 0) - MOD * (ret >= (ll)MOD);
	}
	ll _pow(ll x, ll n, ll MOD) {
		ll ret = 1; x %= MOD;
		for (; n; n >>= 1) {
			if (n & 1) ret = Mul(ret, x, MOD);
			x = Mul(x, x, MOD);
		}
		return ret;
	}
	bool Check(ll x, ll p) {
		if (x % p == 0) return 0;
		for (ll d = x - 1; ; d >>= 1) {
			ll t = _pow(p, d, x);
			if (d & 1) return t != 1 && t != x - 1;
			if (t == x - 1) return 0;
		}
	}
	bool IsPrime(ll x) {
		if (x == 2 || x == 3 || x == 5 || x == 7) return 1;
		if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0) return 0;
		if (x < 121) return x > 1;
		if (x < 1ULL << 32) for (auto& i : { 2, 7, 61 }) {
			if (x == i) return 1;
			if (x > i && Check(x, i)) return 0;
		}
		else for (auto& i : { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 }) {
			if (x == i) return 1;
			if (x > i && Check(x, i)) return 0;
		}
		return 1;
	}
} M;

struct PollardRho : public MillerRabin {
	void Rec(ll n, vector<ll>& v) {
		if (n == 1) return;
		if (~n & 1) { v.push_back(2); Rec(n >> 1, v); return; }
		if (IsPrime(n)) { v.push_back(n); return; }
		ll a, b, c, g = n;
		auto f = [&](ll x) { return (c + Mul(x, x, n)) % n; };
		do {
			if (g == n) {
				a = b = Rand.GetInt<ll>(0, n - 3) + 2;
				c = Rand.GetInt<ll>(0, 19) + 1;
			}
			a = f(a); b = f(f(b)); g = gcd(abs(a - b), n);
		} while (g == 1);
		Rec(g, v); Rec(n / g, v);
	}
	vector<ll> Factorize(ll n) {
		vector<ll> ret; Rec(n, ret);
		sort(ret.begin(), ret.end());
		return ret;
	}
} P;

ll a, b;

void sol() {
	unordered_map<ll, ll> fac;
	ll tmp;

	if (a % 2 == 0) a++;

	for(ll k = a; k <= b; k += 2) {
		if (M.IsPrime(k)) {
			cout << k << ' ';
		}
		else {
			fac.clear();
			for(ll f : P.Factorize(k)) {
				if (fac.find(f) != fac.end()) {
					fac[f] += 2LL;
				}
				else {
					fac.emplace(f, 2LL);
				}
			}

			bool check = true;

			for(auto& [f, cnt] : fac) {
				if (!check) break;

				ll tmp = k - 1LL;
				ll e = 0LL;
				while (tmp >= f) {
					e += tmp / f;
					tmp /= f;
				}
				check = e >= cnt;
			}

			if (!check) cout << k << ' ';
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cin >> a >> b;
	sol();
}