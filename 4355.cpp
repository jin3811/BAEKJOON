#include <iostream>
#define endl '\n'
using namespace std;
using ul = uint64_t;

ul sol(int n) {
	if (n == 1) return 0L;
	ul res = n;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			res /= i;
			res *= (i - 1);
		}
		while (n % i == 0) n /= i;
	}
	if (n != 1) {
		res /= n;
		res *= (n - 1);
	}

	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int n;
	while (true) {
		cin >> n;
		if (!n) break;
		cout << sol(n) << endl;
	}
}