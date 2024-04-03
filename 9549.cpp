#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

string en, de;

void sol() {
	map<char, int> appear, sub;
	bool res;
	int width = en.length() - de.length();
	
	for (char& d : de) appear[d]++;
	for (int i = 0; i < de.length()-1; i++) sub[en[i]]++;

	for (int i = 0; i <= width; i++) {
		res = true;
		if (i > 0) sub[en[i - 1]]--;
		sub[en[i + de.length() - 1]]++;
		for (auto& [a, c] : sub) {
			res = res && appear[a] == c;
		}
		if (res) {
			cout << "YES" << endl;
			return;
		}		
	}
	cout << "NO" << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int tc;
	cin >> tc;
	cin.ignore();
	while(tc--) {
		cin >> en >> de;
		sol();
	}
}