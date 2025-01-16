#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, m;

void sol(int prev, int cnt, string output) {
	if (cnt == m) {
		cout << output << endl;
	}

	for (int i = prev + 1; i <= n; i++) {
		sol(i, cnt + 1, output + to_string(i) + " ");
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	sol(0, 0, "");
}