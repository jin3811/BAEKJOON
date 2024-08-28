#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

vector<vector<int>> board, score;
vector<vector<bool>> visited;
queue<pair<int,int>> q;

int dfs(int x, int y) {
	int res = 1;
	visited[y][x] = true;
	q.push({x, y});

	for (int d = 0; d < 4; d++) {
		int new_x = x + dx[d], new_y = y + dy[d];

		if (new_x < 1 || new_x > m ||
			new_y < 1 || new_y > n ||
			board[new_y][new_x] != board[y][x] || 
			visited[new_y][new_x]) {
			continue;
		}
		res += dfs(new_x, new_y);
	}
	return res;
}

void marking_score() {
	int cnt;
	for(int y = 1; y <= n; y++) {
		for(int x = 1; x <= m; x++) {
			if (!visited[y][x]) {
				cnt = dfs(x, y);
				while(!q.empty()) {
					auto [vx, vy] = q.front();
					q.pop();
					score[vy][vx] *= cnt;
				}
			}
		}
	}
}

struct Dice {
	int number[4][3] = {
		{-1, 2, -1}, //    북
		{ 4, 1, 3 }, // 서 상 동
		{-1, 5, -1}, //    남 
		{-1, 6, -1}, //    하
	};

	int get_under_num() {
		return number[3][1];
	}

	void role_dice(char dir) {
		int tail;
		if (dir == 'n') { // 북쪽 회전
			for (int i = 1; i < 4; i++) {
				swap(number[i - 1][1], number[i][1]);
			}
		}
		else if (dir == 's') { // 남쪽 회전
			for (int i = 3; i > 0; i--) {
				swap(number[i][1], number[i - 1][1]);
			}
		}
		else if (dir == 'e') { // 동쪽 회전
			rotate(number[1], number[1] + 2, number[1] + 3);
			swap(number[1][0], number[3][1]);
		}
		else if (dir == 'w') { // 서쪽 회전
			rotate(number[1], number[1] + 1, number[1] + 3);
			swap(number[1][2], number[3][1]);
		}
		else assert(false);
	}
	
	// void show_dice() {
	// 	for(int y = 0; y < 4; y++) {
	// 		for(int x = 0; x < 3; x++) {
	// 			if (number[y][x] == -1) cout << "  ";
	// 			else cout << number[y][x] << ' ';
	// 		}
	// 		cout << endl;
	// 	}
	// }
};

void input() {
	cin >> n >> m >> k;
	board.resize(n + 1, vector<int>(m + 1));
	visited.resize(n + 1, vector<bool>(m + 1));
	for(int y = 1; y <= n; y++) {
		for(int x = 1; x <= m; x++) {
			cin >> board[y][x];
		}
	}
	score = board;
	marking_score();
}

void sol() {
	Dice d;
	int res = 0;
	char dcode[] = "eswn";
	int dx[] = {1, 0, -1, 0};
	int dy[] = {0, 1, 0, -1};
	int dir = 0, x = 1, y = 1, nx, ny;

	while(k--) {
		/**
		 * 다음 방향 결정 --- 결정할수 있으면 결정한 방향 -> 이동 -> 점수 더하기
		 * 				   |- 이동할수 없다면 반대방향
		 * 방향 결정을 먼저 하는 이유 : n=2, m=1일때 조건대로 동쪽으로 닥돌하면 터짐.
		 * 물론 이번 문제는 n,m 이 모두 2 이상이라 상관은 없지만, 앞으로 어떤 문제가 나올지 모르기에
		 * 해당 문제도 똑같이 적용
		 */
		// 다음 방향 결정 : 경계값 체크
		nx = x + dx[dir], ny = y + dy[dir];
		if (nx < 1 || nx > m || ny < 1 || ny > n) {
			dir = (dir + 2) % 4;
			nx = x + dx[dir], ny = y + dy[dir];
		}

		// 이동
		x = nx, y = ny;
		d.role_dice(dcode[dir]);

		// 점수 더하기
		res += score[y][x];

		// 다음 방향 정하기2 : 현재 위치와 주사위 밑면
		if (d.get_under_num() > board[y][x]) {
			dir = (dir + 1) % 4;
		}
		else if (d.get_under_num() < board[y][x]) {
			dir = (dir + 3) % 4;
		}
	}

	cout << res;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}