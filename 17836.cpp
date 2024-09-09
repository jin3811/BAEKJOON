#include <bits/stdc++.h>
#define MARK 9
#define FAIL 999999
using namespace std;

int n, m, swx, swy, lim;
vector<vector<int>> arr;

void input() {
	cin >> n >> m >> lim;
	arr.resize(n, vector<int>(m));
	for(int y = 0; y < n; y++) {
		for(int x = 0; x < m; x++) {
			cin >> arr[y][x];
			if (arr[y][x] == 2) {
				swy = y, swx = x;
			}
		}
	}
}

int bfs(int stx, int sty, int edx, int edy) {
	vector<vector<int>> graph{arr};
	queue<tuple<int, int, int>> q;
	int dist = FAIL;
	int dx[] = {1, 0, -1, 0};
	int dy[] = {0, 1, 0, -1};
	
	graph[sty][stx] = MARK;
	q.push({stx, sty, 0});

	while(!q.empty()) {
		auto [cur_x, cur_y, cur_dist] = q.front();
		q.pop();

		if (cur_x == edx && cur_y == edy) {
			dist = cur_dist;
			break;
		}

		for(int d = 0; d < 4; d++) {
			int new_x = cur_x + dx[d], new_y = cur_y + dy[d];
			if (new_x < 0 || new_x >= m ||
				new_y < 0 || new_y >= n ||
				graph[new_y][new_x] == 1 || 
				graph[new_y][new_x] == MARK) {
				continue;
			}

			graph[new_y][new_x] = MARK;
			q.push({new_x, new_y, cur_dist + 1});
		}
	}
	return dist;
}

void sol() {
	int answer = min(
		bfs(0, 0, m - 1, n - 1),
		bfs(0, 0, swx, swy) + abs(swx - m + 1) + abs(swy - n + 1)
	);
	if (answer > lim || answer == FAIL) cout << "Fail";
	else cout << answer;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}