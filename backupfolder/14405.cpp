#include <bits/stdc++.h>
using namespace std;

string str;

void sol() {
	size_t idx = 0, len = str.length();
	bool res = true;

	while (idx < len && res) {
		if (str[idx] == 'p') {
			if (idx >= len - 1 ||
				str[idx + 1] != 'i') {

				res = false;
			}
			idx += 2;
		}
		else if (str[idx] == 'k') {
			if (idx >= len - 1 ||
				str[idx + 1] != 'a') {

				res = false;
			}
			idx += 2;
		}
		else if (str[idx] == 'c') {
			if (idx >= len - 2 ||
				str[idx + 1] != 'h' ||
				str[idx + 2] != 'u') {

				res = false;
			}
			idx += 3;
		}
		else {
			res = false;
		}
	}
	cout << (res ? "YES" : "NO");
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cin >> str;
	sol();
}