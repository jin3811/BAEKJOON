#include <bits/stdc++.h>
using namespace std;

vector<string> words(5);
int max_len;

void input() {
	for(auto& w : words) {
		cin >> w;
		max_len = max(max_len, (int)w.length());
	}
}

void sol() {
	for (int x = 0; x < max_len; x++) {
		for (int y = 0; y < 5; y++) {
			if (words[y].length() <= x) continue;
			cout << words[y][x];
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}