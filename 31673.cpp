#include <bits/stdc++.h>
#define ALL(X) X.rbegin(), X.rend()
using namespace std;
using ll = long long;

ll n, m, total;
vector<ll> club;

void input() {
	cin >> n >> m;
	club.resize(n);
	for(ll& x : club) cin >> x;
	sort(ALL(club));
	total = accumulate(ALL(club), 0LL);
}

void sol() {
	ll half_total = total >> 1; // 반대표 최대
	size_t i = 0;
	for(; i < club.size(); i++) {
		total -= club[i];
		if (total <= half_total) break;
	}
	cout << m / (i + 2);
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}