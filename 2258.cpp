/**
 * boj/2258
 * 
 * 비용 우선 오름차순, 무게 내림차순 정렬
 * 무게 누적합해가면서 최소비용 찾기
 */
#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

int n, m;
vector<pll> meat;

void input() {
	int a, b;
	cin >> n >> m;
	meat.resize(n);
	for(auto& [w, c] : meat) cin >> w >> c;
	sort(ALL(meat), [](const pll& a, const pll& b){
		if (a.second != b.second) return a.second < b.second;
		else return a.first > b.first; 
	});
}

void sol() {
	ll ans = __LONG_LONG_MAX__, tmp = meat[0].second;

	if (meat[0].first >= m) {
		ans = min(ans, meat[0].second);
	}
	else {
		for(int i = 1; i < n; i++) {
			if (meat[i].second != meat[i - 1].second) {
				tmp = meat[i].second;
			}
			else {
				tmp += meat[i].second;
			}

			meat[i].first += meat[i - 1].first;
			if (meat[i].first >= m) {
				ans = min(ans, tmp);
			}
		}
	}

	cout << (ans == __LONG_LONG_MAX__ ? -1 : ans);
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}