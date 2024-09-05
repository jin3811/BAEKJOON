#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int l, r, c;
vector<vector<string>> building;
tuple<int,int,int> st;

void input() {
	size_t s;
	building = vector<vector<string>>(l, vector<string>(r));

	for(int floor = 0; floor < l; floor++) {
		for(int row = 0; row < r; row++) {
			auto& line = building[floor][row];
			cin >> line;
			s = line.find('S');
			if (s != string::npos) {
				st = {floor, row, s};
			}
		}
	}
}

int bfs() {
	int res = -1;
	queue<tuple<int,int,int,int>> q; // x, y, z, dist;
	int dx[] = {0, 1, 0, -1, 0, 0};
	int dy[] = {-1, 0, 1, 0, 0, 0};
	int dz[] = {0, 0, 0, 0, 1, -1};

	auto& [z, y, x] = st;

	q.push({x, y, z, 0});
	
	while(!q.empty()) {
		auto [cx, cy, cz, cdist] = q.front();
		q.pop();

		if (building[cz][cy][cx] == 'E') {
			res = cdist;
			break;
		}

		for(int d = 0; d < 6; d++) {
			int nx = cx + dx[d], ny = cy + dy[d], nz = cz + dz[d];

			if (nx < 0 || nx >= c ||
				ny < 0 || ny >= r ||
				nz < 0 || nz >= l) {
				continue;
			}

			auto& next_step = building[nz][ny][nx];

			if (next_step == '#' ||
				next_step == 'S' ||
				next_step == '-') {
					continue;
				}

			if (next_step == '.') next_step = '-';	
			q.push({nx, ny, nz, cdist + 1});
		}
	}
	return res;
}

void sol() {
	int dist = bfs();
	if (dist == -1) {
		cout << "Trapped!";
	}
	else {
		cout << "Escaped in " << dist << " minute(s).";
	}
	cout << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	while (true) {
		cin >> l >> r >> c;
		if (!l && !r && !c) break;
		input();
		sol();
	}
}