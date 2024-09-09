#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;

string s, t;

void sol() {
	while(s.length() < t.length()) {
		if (*t.rbegin() == 'A') {
			t.erase(t.end() - 1);
		}
		else {
			t.erase(t.end() - 1);
			reverse(ALL(t));
		}
	}
	cout << (s == t);
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cin >> s >> t;
	sol();
}