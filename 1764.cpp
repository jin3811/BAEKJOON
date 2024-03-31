#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n, m, cnt;
map<string, int> people;

void input() {
	string tmp;
	cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		cin >> tmp;
		if (++people[tmp] == 2) cnt++;
	}
}

void sol() {
	cout << cnt << endl;
	for (auto& [n, x] : people) {
		if (x == 2) {
			cout << n << endl;
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}