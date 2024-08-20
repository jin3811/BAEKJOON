#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> gh, dp;

void input() {
	int a, b;
	cin >> n;
	gh.resize(n + 1), dp.resize(n + 1, vector<int>(2, -1));
	
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		gh[a].push_back(b);
		gh[b].push_back(a);
	}
}

int dfs(int cur, int parent, int state) {
	if (dp[cur][state] != -1) {
		return dp[cur][state]; // 메모이제이션
	}

	dp[cur][state] = state;

	if (state == 1) { // 내가 켜져있다면, 자식은 켜져도 되고 안켜져도 된다.
		for (int& nxt : gh[cur]) {
			if (nxt == parent) {
				continue;
			}
			dp[cur][state] += min(dfs(nxt, cur, 1), dfs(nxt, cur, 0));
		}
	}
	else { // 내가 꺼져있다면, 자식은 켜져있어야만 정답 조건에 부합한다.
		for (int& nxt : gh[cur]) {
			if (nxt == parent) {
				continue;
			}
			dp[cur][state] += dfs(nxt, cur, 1);
		}
	}
	return dp[cur][state];
}

void sol() {
	// 어떤 노드를 지정해도 트리의 루트가 될 수 있다.
	dfs(1, 0, 1); // 1번 노드가 켜져있는 경우의 최소
	dfs(1, 0, 0); // 1번 노드가 꺼져있는 경우의 최소
	cout << min(dp[1][0], dp[1][1]);
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}