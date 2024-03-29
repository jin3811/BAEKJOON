#include <bits/stdc++.h>
using namespace std;

int atk, def;

void sol() {
	char win[2][3] = {"yt", "yj"};
	int idx = 0;
	while (1) {
		def += atk;
		if (def >= 5) {
			cout << win[idx];
			return;
		}
		swap(atk, def);
		idx = (idx + 1) % 2;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cin >> atk >> def;
	sol();
}