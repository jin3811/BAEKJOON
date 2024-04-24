#include <bits/stdc++.h>
using namespace std;

int n, s;
vector<int> v;

void input() {
	cin >> n >> s;
	v.resize(n);
	for(int& x : v) cin >> x;
}

void sol() {
	int l = 0, r = 0, sum = 0, res = 0;
	while(1) {
		if (sum >= s) {
			res = res ? min(res, r - l) : r - l;
			sum -= v[l++];
		}
		else if (r == n) break;
		else sum += v[r++];
	}
	cout << res;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}