#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	string keys[4] = {
		"`1234567890-=",
		"QWERTYUIOP[]\\",
		"ASDFGHJKL;'",
		"ZXCVBNM,./"
	};
	string wrong;
	map<char, char> key_map;

	key_map[' '] = ' ';
	for_each(keys, keys+4, [&key_map](const string& str){
		for (int i = 1; i < str.length(); i++) {
			key_map[str[i]] = str[i - 1];
		}
	});
	// for (auto& qwerty : keys) {
	// 	for (int i = 1; i < qwerty.length(); i++) {
	// 		key_map[qwerty[i]] = qwerty[i - 1];
	// 	}
	// }

	while(getline(cin, wrong, '\n')) {
		for(char c : wrong) cout << key_map[c];
		cout << endl;
	}
}