#include <bits/stdc++.h>
using namespace std;

vector<int> guest;

void input() {
	int n;
	cin >> n;
	guest.resize(n);
	for(int& g : guest) cin >> g;
}

void sol() {
	__int128_t seats = 0, bit = 1;
	int ans = 0;
	for(int g : guest) {
		if (seats & (bit << g)) ans++;
		else seats |= (bit << g);
	}
	cout << ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}