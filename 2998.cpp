#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string bin, ans;
	map<string, string> h2b = {
		{"000", "0"},
		{"001", "1"},
		{"010", "2"},
		{"011", "3"},
		{"100", "4"},
		{"101", "5"},
		{"110", "6"},
		{"111", "7"},
	};

	cin >> bin;
	bin = string((3-bin.length()%3)%3, '0') + bin;

	for(int i = 0; i < bin.length(); i+=3) {
		ans.append(h2b[bin.substr(i, 3)]);
	}
	cout << ans;
}