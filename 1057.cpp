#include <bits/stdc++.h>
using namespace std;

int rd, n, m;

void input() {
	cin >> rd >> n >> m;
}

int new_num(int n) {
	return (n + 1) / 2;
}

void sol() {
	int cnt = 1;
	while(new_num(n) != new_num(m)) {
		n = new_num(n);
		m = new_num(m);
		cnt++;
	}
	cout << cnt;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cin >> rd >> n >> m;
	sol();
}