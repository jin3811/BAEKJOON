#include <bits/stdc++.h>
using namespace std;
using ul = uint64_t;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	ul fib[81] = {1,1,};
	int n;

	for (int i = 2; i <= 80; i++) {
		fib[i] = fib[i-1]+fib[i-2];
	}

	cin >> n;
	cout << 2ULL * (fib[n] + fib[n-1]) << endl;
}