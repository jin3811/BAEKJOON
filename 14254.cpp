#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string prev_password;
int k;

void input() {
	cin >> prev_password >> k;
}

int change(bool change_left) {
	string password = prev_password;
	int l = 0, r = password.length() - k;
	int cnt = 0;

	while (r < password.length()) {
		if (password[l] != password[r]) {
			if (change_left) password[l] = password[r];
			else password[r] = password[l];
			cnt++;


			cout << "-------------------------\n";
			cout << "where   : " << (change_left ? "chage left" : "chage right") << endl;
			cout << "origin  : " << prev_password << endl;
			cout << "new     : " << password << endl;
			cout << "forward : " << password.substr(0, k) << endl;
			cout << "back    : " << "" << password.substr(password.length() - k, k) << endl;
			cout << "cnt     : " << cnt << endl;
			cout << "-------------------------\n";
		}

		l++, r++;

		if (password.substr(0, k) == password.substr(password.length() - k, k)) {

			cout << "\n\nDONE\n\n\n";
			return cnt;
		}
	}
	cout << "\n\nDONE\n\n\n";
	return 1000;
}

void sol() {
	int l = change(true);
	int r = change(false);
	cout << min(l, r);
}

int main () {
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);
	input();
	sol();
}