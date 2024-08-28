#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> graph;
int n, st, ed;

void input() {
	int m, a, b, d;
	cin >> n >> m;
	graph.resize(n + 1);
	while (m--) {
		cin >> a >> b >> d;
		graph[a].push_back({d, b});
		graph[b].push_back({d, a});
	}
	cin >> st >> ed;
}

bool bfs(int weight) {
	queue<int> q;
	vector<bool> visited(n + 1);
	
	visited[st] = true;
	q.push(st);

	while(!q.empty()) {
		int cur = q.front();
		q.pop();

		for(auto& [nxt_cost, nxt_pos] : graph[cur]) {
			if (nxt_cost < weight) continue;
			if (visited[nxt_pos]) continue;

			visited[nxt_pos] = true;
			q.push(nxt_pos);
		}
	}
	return visited[ed];
}

// 정해 : 이분탐색으로 가능한 최댓값 찾기.
void sol() {
	int low = 1, high = 1e9 + 1, mid;
	while(low <= high) {
		mid = (low + high) / 2;
		if (bfs(mid)) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << high;
}

// 처음 생각했던 알고리즘 분류 까기 전까지 생각하던 아이디어
// 다익 느낌으로 bfs 돌면서 도착지점에 도달할때까지의 최대 무게
void sol2() {
	queue<tuple<int, int, int>> q;
	vector<int> cost(n + 1, -1);
	
	q.push({int(1e9) + 100, st, 0});
	cost[st] = 0;

	while(!q.empty()) {
		auto [cur_cost, cur_pos, prev_pos] = q.front();
		q.pop();

		cost[cur_pos] = max(cur_cost, cost[cur_pos]);
		if (cur_pos != ed) {
			for(auto& [nxt_cost, nxt_pos] : graph[cur_pos]) {
				if (nxt_pos == prev_pos) continue;
				if (cost[nxt_pos] > cost[cur_pos]) continue;

				if (nxt_cost < cur_cost) {
					q.push({nxt_cost, nxt_pos, cur_pos});
				}
				else {
					q.push({cur_cost, nxt_pos, cur_pos});
				}
			}
		}
	}
	cout << cost[ed];
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
	// sol2();
}