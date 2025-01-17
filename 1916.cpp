/**
 * boj/1916
 * 평범한 최단경로 문제이다. 간선의 정보가 모두 양수이니 다익스트라로 처리하면 끝
 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using pii = pair<int, int>;

int n, m, qst, qed;
vector<vector<pii>> graph;

void input() {
	int st, ed, dist;
	cin >> n >> m;
	graph.resize(n + 1);
	for(int i = 0; i < m; i++) {
		cin >> st >> ed >> dist;
		graph[st].push_back({dist, ed});
	}
	cin >> qst >> qed;
}

int dijkstra(int st, int dest) {
	vector<int> dist_arr(n + 1, INT32_MAX);
	priority_queue<pii> pq;

	dist_arr[qst] = 0;
	pq.push({0, qst});

	while(!pq.empty()) {
		auto [cur_dist, cur_pos] = pq.top();
		pq.pop();

		if (cur_dist > dist_arr[cur_pos]) continue;

		for(auto [next_dist, next_pos] : graph[cur_pos]) {
			if (dist_arr[next_pos] <= next_dist + cur_dist) continue;

			dist_arr[next_pos] = next_dist + cur_dist;
			pq.push({dist_arr[next_pos], next_pos});
		}
	}

	return dist_arr[dest];
}

void sol() {
	cout << dijkstra(qst, qed);
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}