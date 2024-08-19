#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;
using pii = pair<int,int>;

int n, m, t, s, g, h;
vector<vector<pii>> graph;
vector<int> dest;

void input() {
	int a, b, d;
	cin >> n >> m >> t >> s >> g >> h;

	graph.clear();
	graph.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> d;
		graph[a].push_back({-d, b});
		graph[b].push_back({-d, a});
	}

	dest.resize(t);
	for (int& d : dest) cin >> d;
}

void dijkstra(int start, vector<int>& dist) {
	dist.resize(n + 1, (int)1e9);
	priority_queue<pii> pq;

	dist[start] = 0;
	pq.push({0, start});

	while(!pq.empty()) {
		auto [cur_d, cur] = pq.top();
		pq.pop();

		if (dist[cur] < cur_d) continue;

		for(auto& [nxt_d, nxt] : graph[cur]) {
			if (dist[nxt] > dist[cur] - nxt_d) {
				dist[nxt] = dist[cur] - nxt_d;
				pq.push({-dist[nxt], nxt});
			}
		}
	}
}

void sol() {
	vector<int> s_dist, g_dist, h_dist, answer;
	dijkstra(s, s_dist); // 시작지점에서의 최단거리
	dijkstra(g, g_dist); // 교차로 노드1에서의 최단거리
	dijkstra(h, h_dist); // 교차로 노드2에서의 최단거리

	for(int t : dest) {
		if (s_dist[t] == s_dist[g] + g_dist[h] + h_dist[t] || 
			s_dist[t] == s_dist[h] + h_dist[g] + g_dist[t]) {
			answer.push_back(t);
		}
	}

	sort(ALL(answer));
	for(int& a : answer) cout << a << ' ';
	cout << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int tc;
	cin >> tc;
	while (tc--) {
		input();
		sol();
	}
}