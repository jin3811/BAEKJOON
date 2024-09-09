#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;

string s, rs, t;

void input() {
	cin >> s >> t;
	rs = s;
	reverse(ALL(rs));
}

bool is_substr(string target) {
	if (target.find(s) != string::npos ||
		target.find(rs) != string::npos) return true;
	return false;
}

int back_tracking(string target) {
	// if (r - l + 1 == s.length()) {
	// 	return s == t.substr(l, r - l + 1);
	// }
	// if(!is_substr(t.substr(l, r - l + 1))) {
	// 	return 0;
	// }

	// int res = 0;
	// if (t[r] == 'A') {
	// 	res |= back_tracking(l, r - 1);
	// }
	// if (t[l] == 'B') {
	// 	reverse(t.begin() + l + 1, t.begin() + r + 1);
	// 	res |= back_tracking(l + 1, r);
	// }
	// return res;

	if (target.length() == s.length()) {
		return s == target;
	}
	if (!is_substr(target)) {
		return 0;
	}

	int res = 0;
	if (*target.rbegin() == 'A') {
		res |= back_tracking(target.substr(0, target.length() - 1));
	}
	if (*target.begin() == 'B') {
		string tmp = target.substr(1, target.length());
		reverse(tmp.begin(), tmp.end());
		res |= back_tracking(tmp);
	}
	return res;
}

void sol() {
	// cout << back_tracking(0, t.length() - 1);
	cout << back_tracking(t);
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}