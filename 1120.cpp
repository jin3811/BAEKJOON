#include <bits/stdc++.h>
using namespace std;

string a, b;

void sol() {
	int ans = 999;
	for(int d = 0; d <= b.length() - a.length(); d++) {
		int tmp = 0;
		for (int i = 0; i < a.length(); i++) {
			if (a[i] != b[d+i]) ++tmp;
		}
		ans = min(ans, tmp);
	}
	cout << ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cin >> a >> b;
	sol();
}
