/**
 * boj/11660
 * 입력받은 2차원 배열의 각 행을 누적합으로 변환한 후, 쿼리로 지정된 영역을 누적합 연산으로 처리
 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, m;
vector<vector<int>> table;
vector<tuple<int,int,int,int>> query;

void input() {
	cin >> n >> m;
	table.resize(n+1, vector<int>(n+1));
	query.resize(m);

	for(int x = 1; x <= n; x++) {
		for(int y = 1; y <= n; y++) {
			cin >> table[x][y];
			table[x][y] += table[x][y-1];
		}
	}

	for(auto& [x1, y1, x2, y2] : query) {
		cin >> x1 >> y1 >> x2 >> y2;
	}
}

void sol() {
	int ans;
	for(auto [x1, y1, x2, y2] : query) {
		ans = 0;

		for(; x1 <= x2; x1++) {
			ans += table[x1][y2];
			ans -= table[x1][y1 - 1];
		}

		cout << ans << endl;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol();
}