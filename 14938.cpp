/**
 * boj/14938
 * 
 * 최단경로를 찾으라는 문제임은 자명하다. 다만, 문제에서 특정 정점에서 시작하라는 조건이 없고, 어디에서든 특정 거리 안의 값들의 최댓값을 구하라는 문제이다.
 * 플로이드 워셜로 한 정점에서 특정 거리 안에 있는 정점들의 아이템 개수의 총합의 최댓값을 세주면 된다.
 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<vector<int>> graph;
vector<int> item;
int n, m;

void input() {
	int area1, area2, dist, r;
	cin >> n >> m >> r;
	graph.resize(n + 1, vector<int>(n + 1, 123456));
	item.resize(n + 1);

	for(int i = 0; i <= n; i++) graph[i][i] = 0;
	for(int i = 1; i <= n; i++) cin >> item[i];
	while(r--) {
		cin >> area1 >> area2 >> dist;
		graph[area1][area2] = dist;
		graph[area2][area1] = dist;
	}
}

void sol() {
	int ans = 0, temp;

	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	for(int row = 1; row <= n; row++) {
		temp = 0;
		for(int col = 1; col <= n; col++) {
			if (graph[row][col] <= m) {
				temp += item[col];
			}
		}
		ans = max(ans, temp);
	}

	cout << ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}