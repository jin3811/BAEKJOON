#include <bits/stdc++.h>
using namespace std;

string input;

void sol() {
	int ans = 9999, tmp = 0, cnt = 0, r = 0, l = 1;

	for(char& c : input) if (c == 'b') cnt++;

	for(; r < cnt; r++) {
		if (input[r] == 'a') tmp++;
	}
	ans = min(tmp, ans);

	for(; l < input.length(); r = (r + 1) % input.length(), l++) {
		if (input[r] == 'a') tmp++;

		if (input[l - 1] == 'a') tmp--;
		ans = min(tmp, ans);
	}
	cout << ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cin >> input;
	sol();
}