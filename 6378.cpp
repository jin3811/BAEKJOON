#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	string n;
	int tmp;
	
	while(cin >> n) {
		if (n == "0") break;

		while(n.length() > 1) {
			tmp = 0;
			for(char& c : n) tmp += c - '0';
			n = to_string(tmp);
		}

		cout << n << endl;
	}
}