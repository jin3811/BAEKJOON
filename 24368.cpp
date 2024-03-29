#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int a[3], c, n0;

int h(int n) {
	return (c - a[2]) * n * n - (a[1] * n) - a[0];
}

int sol() {
	if (c == a[2]) { // 직선
		return (a[1] <= 0 && h(n0) >= 0);
	}
	else if (a[2] > c) return 0; // 위볼록
	else { // 아래 볼록
		if (a[1] > 2 * (c - a[2]) * n0) { // n0이 축 왼쪽
			return a[1] * a[1] + 4 * a[0] * (c - a[2]) <= 0;
		}
		else {
			return h(n0) >= 0;
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cin >> a[2] >> a[1] >> a[0] >> c >> n0;
	cout << sol();
}