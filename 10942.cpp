#include <bits/stdc++.h>
#define endl '\n'
#define MAX 2001
using namespace std;

int n, m;
int seq[MAX], dp[MAX][MAX];
vector<pair<int,int>> query;

void input() {
	cin >> n;
	memset(dp, 0xff, sizeof(int)*MAX*MAX);
	for(int i = 1; i <= n; i++) {
		cin >> seq[i];
		dp[i][i] = true;
	}
	cin >> m; query.resize(m);
	for(auto& [s, e] : query) cin >> s >> e;
}

int sol(int s, int e) {
	if (dp[s][e] != -1) {
		return dp[s][e];
	}
	if (s >= e) {
		return 1;
	}

	return dp[s][e] = (seq[s] == seq[e] && sol(s + 1, e - 1));
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	for(auto& [s, e] : query) {
		cout << sol(s, e) << endl;
	}
}