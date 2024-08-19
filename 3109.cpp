#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int r, c;
vector<string> board;

void input() {
	cin >> r >> c;
	board.resize(r);
	for(auto& b : board) cin >> b;
}

int dy[] = {-1, 0, 1};
bool complete;
bool dfs(int y, int x) {
	if(x == c - 1) {
		complete = true;
		return complete;
	}

	int new_y;
	board[y][x] = '-';

	for (int i = 0; i < 3; i++) {
		new_y = y + dy[i];
		if (new_y < 0 || new_y >= r || board[new_y][x + 1] != '.') {
			continue;
		}
		dfs(new_y, x + 1);
		if (complete) {
			break;
		}
		// else {
		// 	board[new_y][x] = '.';
		// }
	}
	return complete;
}

void sol() {
	int answer = 0;
	for (int y = 0; y < r; y++) {
		complete = false;
		if (dfs(y, 0)) {
			answer++;
		}
	}
	cout << answer;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol();
}