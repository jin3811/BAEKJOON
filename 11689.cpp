#include <iostream>
#define endl '\n'
using namespace std;
using ul = uint64_t;

ul n;

void sol() {
	ul res = n;

	for (ul i = 2; i * i <= n; i++) {
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
	cout << res;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cin >> n;
    sol();
}