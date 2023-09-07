#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;

int n, k;
vector<int> v;

void input() {
	cin >> n >> k;
	v.resize(n);
	for(int& x : v) cin >> x;
}

void sol() {
	sort(ALL(v));
	cout << v[k - 1];
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}