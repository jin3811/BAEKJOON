#include <bits/stdc++.h>
using namespace std;

int r, c;
vector<string> board;

void input() {
	cin >> r >> c;
	board.resize(r);
	for(auto& b : board) cin >> b;
}

void sol() {
	int ans = 0;
	for(int y = 0; y < r; y++) {
		for(int x = 0; x < c; x++) {
			if (board[y][x] == '.') continue;

			ans++;
			if (board[y][x] == '-'){
				int tmp_x = x;
				while(tmp_x < c && board[y][tmp_x] == '-') {
					board[y][tmp_x++] = '.';
				}
			}
			else {
				int tmp_y = y;
				while(tmp_y < r && board[tmp_y][x] == '|') {
					board[tmp_y++][x] = '.';
				}
			}
		}
	}
	cout << ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}