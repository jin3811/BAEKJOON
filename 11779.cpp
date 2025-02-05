// #include <bits/stdc++.h>
// #define ALL(X) X.begin(), X.end()
// using namespace std;

// int w, n;
// vector<int> parcel;

// void input() {
//     cin >> w >> n;
//     parcel.resize(n);
//     for(int& p : parcel) cin >> p;
//     sort(ALL(parcel));
// }

// void sol() {
//     vector<vector<pair<int,int>>> arr(400001);
//     bool visited[400001] = {false};

//     for(int i = 0; i < n; i++) {
//         for(int j = i; j < n; j++) {
//             arr[parcel[i] + parcel[j]].push_back({i, j});
//         }
//     }

//     for(int i = 3; i < arr.size(); i++) {

//     }
// }

// int main() {
//     cin.tie(0)->sync_with_stdio(false);
//     input();
//     sol();
// }


#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using pii = pair<int,int>;

int n, m, st, ed;
vector<vector<pii>> graph;


void input() {
	int s, e, d;
	cin >> n >> m;
	graph.resize(n + 1);

	while(m--) {
		cin >> s >> e >> d;
		graph[s].push_back({d, e});
	}

	cin >> st >> ed;
}

void sol() {
	priority_queue<pii, vector<pii>, greater<>> pq;
	int prev[n + 1], dist[n + 1];

	memset(prev, -1, sizeof(int)*(n + 1));
	fill(dist, dist+n+1, INT32_MAX);

	dist[st] = 0;
	pq.push({0, st});

	while(!pq.empty()) {
		auto [cur_d, cur_p] = pq.top(); pq.pop();

		if (cur_d > dist[cur_p]) continue;

		for(auto& [nxt_d, nxt_p] : graph[cur_p]) {
			if (dist[nxt_p] > cur_d + nxt_d) {
				dist[nxt_p] = cur_d + nxt_d;
				prev[nxt_p] = cur_p;
				pq.push({dist[nxt_p], nxt_p});
			}
		}
	}

	int r = ed;
	deque<int> route;
	
	while(1) {
		route.push_back(r);
		if (r != st) r = prev[r];
		else break;
	}

	cout << dist[ed] << endl;
	cout << route.size() << endl;
	while(!route.empty()) {
		cout << route.back() << ' ';
		route.pop_back();
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}