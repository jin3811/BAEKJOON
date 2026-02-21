#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> board = {
	{"STRAWBERRY", 0},
	{"BANANA", 0},
	{"LIME", 0},
	{"PLUM", 0},
};

void input() {
	int n, x;
	string card;
	cin >> n;
	while(n--) {
		cin >> card >> x;
		board[card] += x;
	}
}

void sol() {
	for (auto& [card, cnt] : board){
		if (cnt == 5) {
			cout << "YES";
			return;
		}
	}
	cout << "NO";
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}