#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n;
vector<string> diff;
string symbol = "BSGPD";

void input() {
	cin >> n;
	diff.resize(n);
	for(auto& str : diff) cin >> str;
}

bool cmp(string& s1, string& s2) { // s1 < s2 : true
	if (s1[0] != s2[0]) {
		return symbol.find(s1[0]) < symbol.find(s2[0]);
	}
	else {
		int n1 = stoi(s1.substr(1, s1.length() - 1));
		int n2 = stoi(s2.substr(1, s2.length() - 1));
		return n1 > n2;
	}
}

void sol() {
	if (is_sorted(ALL(diff), cmp)) {
		cout << "OK";
	}
	else {
		cout << "KO\n";

		vector<string> repl = diff;
		sort(ALL(repl), cmp);

		for(int i= n - 1; i >= 0; i--) {
			if (repl[i] != diff[i]) {
				cout << diff[i] << ' ';
			}
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol();
}