#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, atk;
vector<tuple<ll,ll,ll>> dungeon;


void input() {
	cin >> n >> atk;
	dungeon.resize(n);
	for(auto& [t, a, h] : dungeon) cin >> t >> a >> h;
}

void sol() {
	ll ans = 0LL, cur_hp = 0LL;

	for(auto& [t, a, h] : dungeon) {
		if (t == 1) {
			cur_hp -= a * (h / atk - (h % atk ? 0 : 1));
		}
		else {
			atk += a;
			cur_hp = min(0LL, cur_hp + h);
		}
		ans = min(ans, cur_hp);
	}

	cout << 1 - ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol();
}