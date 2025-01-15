/**
 * boj/21938
 * 조건에 맞게 변환하면 2차원 배열이 완성되고, 각 픽셀들이 인접해있으면 같은 물체 라는 조건으로 이 문제는 그래프탐색임을 알 수 있다.
 * 시키는 대로 2차원 배열을 정의하고, bfs 돌리면서 물체 개수 세면 끝
 */
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