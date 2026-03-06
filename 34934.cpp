#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, year;
	string sub;
	cin >> n;
	while(n--) {
		cin >> sub >> year;
		if (year == 2026) cout << sub;
	}
}