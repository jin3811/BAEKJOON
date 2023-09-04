#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int n, value;
	set<int> s;
	string query;

	cin >> n;
	while(n--) {
		cin >> query;

		if (query == "add"){
			cin >> value;
			s.insert(value);
		}
		else if (query == "remove"){
			cin >> value;
			s.erase(value);
		}
		else if (query == "check"){
			cin >> value;
			auto iter = s.find(value);
			cout << (iter != s.end()) << endl;
		}
		else if (query == "toggle"){
			cin >> value;
			auto iter = s.find(value);
			if (iter != s.end()) {
				s.erase(value);
			}
			else {
				s.insert(value);
			}
		}
		else if (query == "all"){
			for (int i = 1; i <= 20; i++) s.insert(i);
		}
		else if (query == "empty"){
			s.clear();
		}
	}
}