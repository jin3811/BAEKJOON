#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;
template<class T>
using Graph = vector<vector<T>>;

int n;

bool check(const string& str) {
	if (str.length() == 1) {
		return true;
	}

	int lim;
	for (int s = 0; s < str.length(); s++) {
		lim = (str.length() - s) / 2;
		for (int l = 1; l <= lim; l++) {
			if (str.substr(s, l) == str.substr(s + l, l)) {
				return false;
			}
		}
	}
	return true;
}

void backTracking(string str, int num) {
	str += to_string(num);

	if (!check(str)) {
		return;
	}
	if(str.length() == n) {
		cout << str;
		exit(0);
	}

	for (int i = 1; i <= 3; i++) {
		backTracking(str, i);
	}
}

void sol() {
	backTracking("", 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	sol();
}