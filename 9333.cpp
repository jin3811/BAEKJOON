#include <bits/stdc++.h>
#define endl '\n'
#define FAIL "impossible"
using namespace std;
using ll = long long;

ll r, b, m;

void input() {
	int r1, r2, b1, b2, m1, m2;
	scanf("%d.%d %d.%d %d.%d", &r1, &r2, &b1, &b2, &m1, &m2);
	r = r1 * 100 + r2; b = b1 * 100 + b2; m = m1 * 100 + m2;
}

void sol() {
	if (b * r / 10000 >= m) {// 이자가 납부금보다 같거나 많으면 이자에 허덕이며 못갚는다.
		cout << FAIL << endl;
		return;
	}

	int month = 0;

	while(++month <= 1200) {
		b = (b * (10000 + r) + 5000) / 10000; // 이자 곱하고 반올림
		b -= m; // 상환

		if (b <= 0) {
			cout << month << endl; // 다 갚았으면 끝
			return;
		}
	}
	cout << FAIL << endl; // 반복문 안에서 return이 안됐으면 실패
}

int main () {
	cin.tie(0)->sync_with_stdio(false);
	int tc;
	scanf("%d", &tc);

	while(tc--) {
		input();
		sol();
	}
}