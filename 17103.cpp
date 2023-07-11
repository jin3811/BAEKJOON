#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define LEN 1000001

bool seive[LEN];

void make_seive() {
	fill(seive, seive + LEN, true);
	seive[0] = seive[1] = false;
	for (int i = 2; i * i <= LEN; i++) {
		if (seive[i]) {
			for (int j = 2; i * j <= LEN; j++) {
				seive[i * j] = false;
			}
		}
	}
}

void sol(int n) {
	int cnt = 0;
	for (int i = 2; i <= n / 2; i++) {
		if (seive[i] && seive[n - i]) cnt++;
	}
	cout << cnt << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	make_seive();
	int tc, n;
	cin >> tc;
	while (tc--) {
		cin >> n;
		sol(n);
	}
}