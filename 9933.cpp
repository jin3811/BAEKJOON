#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;

set<string> pwd;

void input() {
	int n;
	string pw;
	cin >> n;
	while(n--) {
		cin >> pw;
		pwd.insert(pw);
	}
}

void sol() {
	for (auto pw : pwd) {
		reverse(ALL(pw));
		if (pwd.find(pw) != pwd.end()) {
			cout << pw.length() << ' ' << pw[pw.length()/2];
			break;
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}