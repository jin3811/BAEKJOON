#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n;
map<string, int> in, out;

void input() {
	int idx = 0, i;
	string str;
	cin >> n;

	for(i = 0; i < n; i++) {
		cin.ignore();
		cin >> str;
		in[str] = idx++;
	}

	idx = 0;
	for(i = 0; i < n; i++) {
		cin.ignore();
		cin >> str;
		out[str] = idx++;
	}
}

void sol() {
	int ans = 0;
	for(auto& [car, idx] : out) {
		if (in[car] > idx) ans++;
	}
	cout << ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}