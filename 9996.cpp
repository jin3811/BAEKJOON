#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

string pattern, input;
string st, ed;

void split_pattern() {
	stringstream sstream(pattern);
	getline(sstream, st, '*');
	getline(sstream, ed, '*');
}

void sol() {
	if (input.length() < st.length() + ed.length()) {
		cout << "NE" << endl;
	}
	else {
		bool equal_st = st == input.substr(0, st.length());
		bool equal_ed = ed == input.substr(input.length() - ed.length(), ed.length());

		if(equal_st && equal_ed) {
			cout << "DA" << endl;
		}
		else {
			cout << "NE" << endl;
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int tc;
	cin >> tc;
	cin.ignore();
	cin >> pattern;
	split_pattern();
	while(tc--) {
		cin >> input;
		sol();
	}
}