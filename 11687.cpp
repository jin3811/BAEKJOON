#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int m;

int zero_cnt(int num) {
	int n2 = 0, n5 = 0;
	int a2 = 2, a5 = 5;

	while (a2 <= num && a5 <= num) {
		n2 += num / a2;
		a2 *= 2;
		n5 += num / a5;
		a5 *= 5;
	}

	return min(n2, n5);
}

void sol() {
	int st = 1, ed = INT32_MAX - 1, mid, tmp;
	bool flag = false;
	while (st <= ed) {
		mid = (st + ed) / 2;
		tmp = zero_cnt(mid);

		if (tmp == m) flag = true;

		if (tmp < m) {
			st = mid + 1;
		}
		else {
			ed = mid - 1;
		}
	}
	cout << (flag ? st : -1);
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cin >> m;
	sol();
}