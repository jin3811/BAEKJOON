#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string str;

// bool isPalindrome() {
// 	for(int i = 0; i < str.length() / 2; i++) {
// 		if (str[i] != str[str.length() - 1 - i]){
// 			return false;
// 		}
// 	}
// 	return true;
// }

bool isPseudoPaildrome(bool del_flag = false, int i = 0, int l = 0, int r = 1) {
	for(; i < str.length() / 2; i++) {
		if (str[i + l] != str[str.length() - r - i]){
			if (del_flag) {
				return false;
			}
			else {
				// if (str[i + 1] == str[str.length() - 1 - i]) {
				// 	l++;
				// }
				// else if(str[i] == str[str.length() - 2 - i]) {
				// 	r--;
				// }
				// else {
				// 	return false;
				// }
				return isPseudoPaildrome(true, i, l+1, r) ||
						isPseudoPaildrome(true, i, l, r+1);
			}
		}
	}
	return true;
}

void sol() {
	int r;
	// if (isPalindrome()) {
	if (isPseudoPaildrome(true)) {
		r = 0;
	}
	else if (isPseudoPaildrome()) {
		r = 1;
	}
	else {
		r = 2;
	}
	cout << r << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int tc; cin >> tc;
	while(tc--) {
		cin >> str;
		sol();
	}
}