#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int ans=0;
	char c;
	cin >> c;
	for (auto& y : string("ILOVEYONSEI")) {
		ans += abs(y - c);
		c = y;
	}
	cout << ans;
}