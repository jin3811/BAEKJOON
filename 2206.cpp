/**
 * boj/2206
 * 그래프 탐색의 응용문제. 최단경로를 찾되, 장애물을 무시할 수 있는 기회가 생긴다.
 * 다음 위치로 넘어가기 전에, 벽을 부수고 왔는지를 기록하면서 넘어간다. 
 * 벽을 부수고 오지 않았는데, 벽을 만난 경우 부수고 간다는 선택지를 추가할 수 있기 때문이다.
 * 
 * 방문했는지 체크하기 위한 배열에 단순히 방문했는지(true/false)를 기록하는 것이 아닌 벽을 부순 개수를 기록한다.
 * visitied 배열의 값 -> -1 : 방문안함 0 : 벽안부수고 방문 1 : 벽 1개부수고 방문
 * 
 * 만약 다음 방문할 곳의 visited 값이 -1이라면 벽을 부수고 온 개수에 상관 없이 방문해야한다.
 * 값이 0이라면 벽을 부수고 온 개수에 상관 없이 방문할 필요가 없다. 이미 해당 지점에 효율적으로(벽을 부수지 않고 최단거리로) 왔다는 뜻이기 때문이다.
 * 값이 1이고, 현재까지 벽을 부수지 않았다면, 새로 갱신할 필요가 있다. 어떤 한 지점에 오기 위해 벽을 부순 것 보다 벽을 부수지 않고 온 것이 더 효율적이기 때문이다.
 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, m;
vector<string> graph;

void input() {
	cin >> n >> m;
	graph.resize(n);
	for(auto& row : graph) cin >> row;
}

void sol() {
	queue<tuple<int,int,int,int>> q; // 거리, 다음위치 row, col, 벽부순개수
	vector<vector<int>> visited(n, vector<int>(m, -1)); // -1 : 방문안함 0 : 벽안부수고 방문 1 : 벽 부수고 방문
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	int ans = -1;

	q.push({1, 0, 0, 0});
	visited[0][0] = 0;

	while(!q.empty()) {
		auto [cur_dist, cur_row, cur_col, break_cnt] = q.front();
		q.pop();

		if (cur_row == n - 1 && cur_col == m - 1) {
			ans = cur_dist;
			break;
		}

		for(int d = 0; d < 4; d++) {
			int nxt_row = cur_row + dy[d];
			int nxt_col = cur_col + dx[d];

			if (nxt_row < 0 || nxt_row >= n ||
				nxt_col < 0 || nxt_col >= m ||
				visited[nxt_row][nxt_col] == 0 ||
				(visited[nxt_row][nxt_col] >= 1 && visited[nxt_row][nxt_col] <= break_cnt) ||
				(break_cnt == 1 && graph[nxt_row][nxt_col] == '1')
			) continue;

			if (graph[nxt_row][nxt_col] == '0') {
				visited[nxt_row][nxt_col] = break_cnt;
				q.push({cur_dist + 1, nxt_row, nxt_col, break_cnt});
			}
			else {
				visited[nxt_row][nxt_col] = break_cnt + 1;
				q.push({cur_dist + 1, nxt_row, nxt_col, break_cnt + 1});
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