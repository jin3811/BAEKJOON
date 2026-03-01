#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int n, l, d, t;

	cin >> n >> l >> d;

	for(int i = 1; i <= n; i++) {
		t = i*(l + 5) - 5;

		if (i < n) {
			for(; t < i*(l + 5); t++) {
				if (t % d == 0) {
					cout << t;
					return 0;
				}
			}
		}
		else {
			for(; t < i*(l + 5)+ d; t++) {
				if (t % d == 0) {
					cout << t;
					return 0;
				}
			}
		}
	}
}