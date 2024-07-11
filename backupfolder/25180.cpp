#include <bits/stdc++.h>
using namespace std;

int n;

void sol() {
	int ans = n / 9 + 2;
	if (n < 9 || n % 9 % 2) {
		--ans;
	}
	else if (n % 9 == 0) {
		ans -= 2;
	}
	cout << ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cin >> n;
	sol();
}
/**
 * 
*/