#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n, m;
vector<int> num;
bool check[8];

void input() {
	cin >> n >> m;
	num.resize(n);
	for (int& x : num) cin >> x;
	sort(ALL(num));
}

void sol(int cnt, string output) {
	if (cnt == m) {
		cout << output << endl;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (check[i]) continue;

		check[i] = true;
		sol(cnt + 1, output + to_string(num[i]) + " ");
		check[i] = false;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol(0, "");
}