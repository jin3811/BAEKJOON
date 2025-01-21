#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, b, h, w, p, a, ans;

	cin >> n >> b >> h >> w;
	ans = b;

	while(h--) {
		cin >> p;
		for(int i = 0; i < w; i++) {
			cin >> a;
			if(a >= n && p * n <= b) {
				ans = min(p * n, ans);
			}
		}
	}

	if (ans == b) cout << "stay home";
	else cout << ans;
}