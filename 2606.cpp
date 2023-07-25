#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;

int cnt;
vector<vector<int>> graph;
bool visited[100];

void input() {
	int net, a, b;

	cin >> cnt >> net;
	graph.resize(cnt + 1);

	while (net--) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
}

int sol(int start) {
	int answer = 0;

	visited[start] = true;
	for (int i : graph[start]) {
		if (visited[i]) continue;
		
		answer += 1 + sol(i);
	}
	return answer;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	cout << sol(1);
}