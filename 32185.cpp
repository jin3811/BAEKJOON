#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, m;
vector<pair<int, int>> stat;

void input() {
	int v, p, s, me;
	cin >> n >> m;
	m--;
	stat.resize(n + 1);
	for(int i = 0; i <= n; i++) {
		cin >> v >> p >> s;
		stat[i] = {v + p + s, i};
		if (i != 0) {
			if (stat[i].first > me) {
				stat[i].first = -1;
			}
		}
		else {
			me = v + p + s;
		}
	}
}

void sol() {
	sort(stat.rbegin(), stat.rend() - 1);
	for(int i = 0; i <= m && stat[i].first >= 0; i++)  {
		cout << stat[i].second << ' ';
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol();
}