#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int n, value;
	bitset<20> s = 0;
	string query;

	cin >> n;
	while(n--) {
		cin >> query;

		if (query == "add"){
			cin >> value;
			s[value - 1] = 1;
		}
		else if (query == "remove"){
			cin >> value;
			s[value - 1] = 0;
		}
		else if (query == "check"){
			cin >> value;
			cout << s[value - 1] << endl;
		}
		else if (query == "toggle"){
			cin >> value;
			s[value - 1].flip();
		}
		else if (query == "all"){
			s = 1048575;
		}
		else if (query == "empty"){
			s = 0;
		}
	}
}