#include <bits/stdc++.h>
using namespace std;

int p, w;
string str;

unordered_map<int, string> numpad {
	{1, " "},
	{2, "ABC"},
	{3, "DEF"},
	{4, "GHI"},
	{5, "JKL"},
	{6, "MNO"},
	{7, "PQRS"},
	{8, "TUV"},
	{9, "WXYZ"},
};


void input() {
	cin >> p >> w;
	cin.ignore();
	getline(cin, str);
}

int atn(char a){
	if (a == ' ') return 1;
	if (a <= 'C') return 2;
	if (a <= 'F') return 3;
	if (a <= 'I') return 4;
	if (a <= 'L') return 5;
	if (a <= 'O') return 6;
	if (a <= 'S') return 7;
	if (a <= 'V') return 8;
	if (a <= 'Z') return 9;
}

void sol() {
	int ans = 0, prev = 0;
	vector<int> button(str.length(), -1);

	button[0] = atn(str[0]);

	for (int i = 1; i < str.length(); i++) {
		button[i] = atn(str[i]);
		// if (button[i-1] == button[i]) ans += w;
		if (button[i] != 1 && 
			button[i-1] == button[i]) ans += w;
	}

	for(int i = 0; i < str.length(); i++) {
		ans += p * (1 + numpad[button[i]].find(str[i]));
	}

	cout << ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol();
}