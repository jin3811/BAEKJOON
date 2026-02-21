#include <bits/stdc++.h>
using namespace std;
using ul = uint64_t;

ul rec_fib_cnt, dp_fib_cnt;

ul rec_fib(int n) {
	if (n <= 2) {
		++rec_fib_cnt;
		return 1ULL;
	}
	else return rec_fib(n - 1) + rec_fib(n - 2);
}

ul dp_fib(int n) {
	ul t1 = 1ULL, t2 = 1ULL, tmp;
	for (int i = 3; i <= n; i++) {
		tmp = t1 + t2;
		t1 = t2;
		t2 = tmp;
		++dp_fib_cnt;
	}
	return t2;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int n;
	cin >> n;
	rec_fib(n); dp_fib(n);
	cout << rec_fib_cnt << ' ' << dp_fib_cnt;
}