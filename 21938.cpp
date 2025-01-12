#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n, m;
vector<vector<int>> pic;

void input() {
	int r, g, b, threshold;

	cin >> n >> m;
	pic.resize(n, vector<int>(m));

	for(auto& row : pic) {
		for(auto& elem : row) {
			cin >> r >> g >> b;
			elem = (r + g + b) / 3;
		}
	}

	cin >> threshold;

	for(auto& row : pic) {
		for(auto& elem : row) {
			elem = elem >= threshold ? 1 : 0;
		}
	}
}

void bfs(int x, int y) {
	queue<pair<int,int>> q;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};

	pic[y][x] = 0;
	q.push({y, x});
	
	while(!q.empty()) {
		auto[cy, cx] = q.front();
		q.pop();
		for(int d = 0; d < 4; d++) {
			int nx = cx + dx[d];
			int ny = cy + dy[d];
			if (nx < 0 || nx >= m ||
				ny < 0 || ny >= n ||
				pic[ny][nx] == 0) {

				continue;
			}

			pic[ny][nx] = 0;
			q.push({ny, nx});
		}
	}
}

void sol() {
	int ans = 0;
	for(int y = 0; y < n; y++){
		for(int x = 0; x < m; x++){
			if (pic[y][x]) {
				ans++;
				bfs(x, y);
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