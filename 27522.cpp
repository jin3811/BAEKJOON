#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;

vector<pair<string, string>> rank_table(8);

void input() {
	for(auto& [time, team] : rank_table) {
		cin >> time >> team;
	}
	sort(ALL(rank_table));
}

void sol() {
	int score[] = {10,8,6,5,4,3,2,1};
	int red = 0, blue = 0;

	for(int i = 0; i < 8; i++) {
		auto& [_, team] = rank_table[i];

		if (team == "B") blue += score[i];
		else red += score[i];
	}
	cout << (red < blue ? "Blue" : "Red");
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}