#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int ans, coupon, stamp;

	while (cin >> coupon >> stamp) {
		ans = coupon;
		while (coupon >= stamp) {
			ans += coupon / stamp;
			coupon = coupon / stamp + coupon % stamp;
		}
		cout << ans << endl;
	}
}