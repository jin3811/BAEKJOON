#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

map<int, string> int2set;
map<string, int> set2int;

void make_map() {
	int2set[0] = "{}";
	string temp;
	for(int i = 1; i <= 15; i++) {
		temp = "{";
		for (int j = 0; j < i; j++) {
			temp.append(int2set[j]);
			if (j != i - 1) {
				temp.append(",");
			}
		}
		temp.append("}");

		int2set[i] = temp;
	}

	for (int i = 0; i <= 15; i++) {
		set2int[int2set[i]] = i;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int tc;
	
	make_map();
	cin >> tc;
	string s1, s2;
	int num1, num2;

	while(tc--) {
		cin >> s1 >> s2;
		num1 = set2int[s1];
		num2 = set2int[s2];
		cout << int2set[num1 + num2] << endl;
	}
}