#include <bits/stdc++.h>
using namespace std;

int e, f, c;

void sol() {
	int sum = e + f, ans = 0;

	while(sum >= c) {
		ans += sum / c;
		sum = sum / c + sum % c;
	}

	cout << ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cin >> e >> f >> c;
	sol();
}