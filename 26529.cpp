#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ul = uint64_t;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	ul fib[46] = {1,1};
	int tc, n;

	for (int i = 2; i <= 45; i++) {
		fib[i] = fib[i-1]+fib[i-2];
	}

	cin >> tc;
	while(tc--) {
		cin >> n;
		cout << fib[n] << endl;
	}
}