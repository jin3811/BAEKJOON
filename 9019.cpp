#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a, b;
bool check[10001];

int D(int n) {
	return (n * 2) % 10000;
}

int S(int n) {
	return (n + 9999) % 10000;
}

int L(int n) {
	int rot = n / 1000;
	n *= 10;
	n %= 10000;
	return n + rot;
}

int R(int n) {
	int rot = (n % 10) * 1000;
	n /= 10;
	return n + rot;
}

string sol() {
	queue<pair<string, int>> q;
	int dn, sn, ln, rn;

	q.emplace("", a);
	check[a] = true;

	while(!q.empty()) {
		auto [cmd, n] = q.front(); q.pop();

		if (b == n) {
			return cmd;
		}
		dn = D(n), sn = S(n), ln = L(n), rn = R(n);

		if (!check[dn]) {
			q.emplace(cmd + "D", dn);
			check[dn] = true;
		}
		if (!check[sn]) {
			q.emplace(cmd + "S", sn);
			check[sn] = true;
		}
		if (!check[ln]) {
			q.emplace(cmd + "L", ln);
			check[ln] = true;
		}
		if (!check[rn]) {
			q.emplace(cmd + "R", rn);
			check[rn] = true;
		}
	}
	assert(false);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int tc; cin >> tc;
	while(tc--) {
		memset(check, 0, 10001);
		cin >> a >> b;
		cout << sol() << endl;
	}
}