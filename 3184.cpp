#include <bits/stdc++.h>
#define CHECKED '-'
using namespace std;

int total_v, total_o, r, c;
vector<string> ground;

void input() {
	cin >> r >> c;
	ground.resize(r);
	for(auto& str : ground) cin >> str;
}

void count_vo(char animal, int& cnt_v, int& cnt_o) {
	if (animal == 'v') {
		cnt_v++;
	}
	else if (animal == 'o') {
		cnt_o++;
	}
}

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	int cnt_v = 0, cnt_o = 0;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};

	q.push({x, y});
	count_vo(ground[y][x], cnt_v, cnt_o);
	ground[y][x] = CHECKED;

	while(!q.empty()) {
		auto [cur_x, cur_y] = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nxt_x = cur_x + dx[i];
			int nxt_y = cur_y + dy[i];

			if (nxt_x < 0 || nxt_x >= c ||
				nxt_y < 0 || nxt_y >= r ||
				ground[nxt_y][nxt_x] == '#' || ground[nxt_y][nxt_x] == CHECKED){
				continue;
			}

			q.push({nxt_x, nxt_y});
			count_vo(ground[nxt_y][nxt_x], cnt_v, cnt_o);
			ground[nxt_y][nxt_x] = CHECKED;
		}
	}

	if (cnt_v >= cnt_o) {
		cnt_o = 0;
	}
	else {
		cnt_v = 0;
	}

	total_v += cnt_v;
	total_o += cnt_o;
}

void sol() {
	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			if (ground[y][x] == 'v' || ground[y][x] == 'o') {
				bfs(x, y);
			}
		}
	}
	cout << total_o << " " << total_v;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}