#include <bits/stdc++.h>
#define endl '\n'
using ll = long long;
using namespace std;

int n, x;
vector<ll> v;

void input() {
	cin >> n >> x;
	v.resize(n);
	for(ll& i : v) cin >> i;
}

void sol() {
	sort(v.begin(), v.end());
	int ans = 0, cnt = 1;
	int l = lower_bound(v.begin(), v.end(), x) - v.begin(), r = n, tmp;
	do {
		tmp = (r - l) / cnt;
		ans += tmp;

		for(int i = 0; i < l; i++) {
			v[i] = v[i] / cnt * (cnt + 1);
		}
		cnt++;

		r -= tmp;
		l = lower_bound(v.begin(), v.begin() + r, x) - v.begin();
	} while((r - l >= cnt));
	if (v[0] / cnt * (r - l) >= x) ans++;
	cout << ans << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int tc; cin >> tc;
	while(tc--) {
		input();
		sol();
	}
}