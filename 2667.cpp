#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;
using pii = pair<int, int>;

vector<string> apart;
int n;

void input() {
	cin >> n;
	apart.resize(n);
	for (auto& str : apart) {
		cin >> str;
	}
}

int bfs(int x, int y) {
	queue<pii> q;
	int area = 0;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	
	q.push({x, y});
	apart[y][x] -= 1;

	while (!q.empty()) {
		pii cur = q.front();
		q.pop();
		area++;
		for (int i = 0; i < 4; i++) {
			pii nxt = {cur.first + dx[i], cur.second + dy[i]};
			if (nxt.first < 0 || nxt.first >= n ||
				nxt.second < 0 || nxt.second >= n || 
				apart[nxt.second][nxt.first] == '0') {
					continue;
				}
			apart[nxt.second][nxt.first] -= 1;
			q.push(nxt);
		}
	}
	return area;
}

void sol() {
	int apart_set_cnt = 0;
	vector<int> apart_total_cnt;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (apart[y][x] != '0') {
				apart_set_cnt++;
				apart_total_cnt.push_back(bfs(x, y));
			}
		}
	}
	sort(ALL(apart_total_cnt));
	cout << apart_set_cnt << endl;
	for (int i : apart_total_cnt) {
		cout << i << endl;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}