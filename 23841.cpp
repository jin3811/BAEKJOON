#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n, m;
vector<string> picture;

void input() {
	cin >> n >> m;
	picture.resize(n);
	for(auto& l : picture) cin >> l;
}

void sol() {
	vector<string> ans(n, string(m, '.'));
	for(int y = 0; y < n; y++){
		for(int x = 0; x < m; x++) {
			if (picture[y][x] != '.') {
				ans[y][x] = picture[y][x];
				ans[y][m - 1 - x] = picture[y][x];
			}
		}
	}
	for_each(ALL(ans), [](string& x) { cout << x << endl; });
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}