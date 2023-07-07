#include <bits/stdc++.h>
#define INF (int)1e9
#define LEN ((int)1e5 + 5)
using namespace std;
using pii = pair<int, int>;

void sol(int n, int k) { // 다익스트라
	int dist_arr[2 * LEN];
	fill(dist_arr, dist_arr + 2 * LEN, INF);
	bool visit[2 * LEN] = { false };
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	pq.push({ 0, n });
	dist_arr[n] = 0;
	
	while(!pq.empty()) {
		pii cur = pq.top();
		pq.pop();
		if (visit[cur.second]) continue;
		visit[cur.second] = true;

		if (cur.second <= k && dist_arr[cur.second * 2] > cur.first) {
			dist_arr[cur.second * 2] = cur.first;
			pq.push({dist_arr[cur.second * 2], cur.second * 2});
		}
		if (cur.second <= 2 * k && dist_arr[cur.second + 1] > cur.first + 1) {
			dist_arr[cur.second + 1] = cur.first + 1;
			pq.push({dist_arr[cur.second + 1], cur.second + 1});
		}
		if (cur.second > 0 && dist_arr[cur.second - 1] > cur.first + 1) {
			dist_arr[cur.second - 1] = cur.first + 1;
			pq.push({dist_arr[cur.second - 1], cur.second - 1});
		}
	}
	cout << dist_arr[k] << endl;
}

void sol2(int n, int k) { // 0-1 BFS
	deque<int> dq;
	int dist_arr[2 * LEN];
	fill(dist_arr, dist_arr + 2 * LEN, INF);
	bool visit[2 * LEN] = { false };
	
	dq.push_front(n);
	dist_arr[n] = 0;

	while(!dq.empty()) {
		int cur = dq.front();
		dq.pop_front();
		if (visit[cur]) continue;
		visit[cur] = true;

		if (cur <= k && dist_arr[cur * 2] > dist_arr[cur]) {
			dist_arr[cur * 2] = dist_arr[cur];
			dq.push_front(cur * 2);
		}
		if (cur <= 2 * k && dist_arr[cur + 1] > dist_arr[cur] + 1) {
			dist_arr[cur + 1] = dist_arr[cur] + 1;
			dq.push_back(cur + 1);
		}
		if (cur > 0 && dist_arr[cur - 1] > dist_arr[cur] + 1) {
			dist_arr[cur - 1] = dist_arr[cur] + 1;
			dq.push_back(cur - 1);
		}
	}
	cout << dist_arr[k];
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k;
	cin >> n >> k;
	sol(n, k);
	// sol2(n, k);
}