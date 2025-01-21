#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, ans = 0;
	cin >> n;
	vector<int> s(n, 0);
	for(int i = 0; i < n; i++) cin >> s[i];

	ans += abs(s[0] - s[2]) * (s[0] > s[2] ? 508 : 108);
	ans += abs(s[1] - s[3]) * (s[1] > s[3] ? 212 : 305);
	ans += s[4] * 707;
	ans *= 4763;

	cout << ans;
}