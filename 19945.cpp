#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int n;
	cin >> n;

	if (n < 0) cout << 32;
	else if (n == 0) cout << 1;
	else cout << (int)log2(n) + 1;
}