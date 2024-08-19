#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;
using pii = pair<int, int>;

int n, d, c;
vector<vector<pii>> graph;

void input() {
	int a, b, s;
	graph.clear();
	cin >> n >> d >> c;
	graph.resize(n + 1);
	for (int i = 0; i < d; i++) {
		cin >> a >> b >> s;
		graph[b].push_back({-s, a});
	}
}

vector<int> dijkstra(int start) {
	vector<int> dist(n + 1, (int)1e9);
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
	return dist;
}

void sol() {
	auto dist = move(dijkstra(c));
	replace_if(ALL(dist), [](int i) {return i == (int)1e9;}, -1);
	cout << count_if(ALL(dist), [](int i) { return i >= 0; })
		 << ' '
		 << *max_element(ALL(dist)) << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int tc;
	cin >> tc;
	while(tc--) {
		input();
		sol();
	}
}