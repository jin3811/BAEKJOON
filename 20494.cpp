#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int n, ans = 0;
	string sushi;
	cin >> n;
	while(n--) {
		cin >> sushi;
		ans += sushi.length();
	}
	cout << ans;
}