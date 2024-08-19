#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n;
vector<string> mineBoard;

void input() {
	cin >> n;
	mineBoard.resize(n);
	for(auto& l : mineBoard) cin >> l;
}

void mineMarking(int y, int x, vector<string>& board) {
	int dx[] = {1,1,1,0,-1,-1,-1,0};
	int dy[] = {-1,0,1,1,1,0,-1,-1};

	board[y][x] = '*';
	
	for (int i = 0; i < 8; i++) {
		int newx = x + dx[i], newy = y + dy[i];
		if (newx < 0 || newx >= n ||
			newy < 0 || newy >= n || 
			board[newy][newx] == 'M' ||
			isdigit(mineBoard[newy][newx])) continue;

		int curCnt = board[newy][newx] - '0';
		int plus = mineBoard[y][x] - '0';

		if (curCnt + plus >= 10) {
			board[newy][newx] = 'M';
		}
		else {
			board[newy][newx] = curCnt + plus + '0';
		}
	}
}

void sol() {
	vector<string> answer(n, string(n, '0'));
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (isdigit(mineBoard[y][x])) {
				mineMarking(y, x, answer);
			}
		}
	}
	for(auto& l : answer) cout << l << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol();
}