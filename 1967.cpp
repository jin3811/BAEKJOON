/**
 * boj/1967
 * 
 * 1167번과 같은 풀이. 입력이 1167번에 비해 굉장히 착한 문제이다.
 */

#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> graph;
int answer = -1;

void input() {
	int st, dest, dist, n;
	cin >> n;
	graph.resize(n + 1);

	while(--n) {
		cin >> st >> dest >> dist;
		graph[st].push_back({dest, dist});
	}
}

void update(pair<int, int>& p, int val) {
	auto& [m1, m2] = p;
	if (val >= m1) {
		m2 = m1;
		m1 = val;
	}
	else if (val > m2) {
		m2 = val;
	}
}

int max_length(int cur, int parent) {
	pair<int, int> length = {0,0};

	for(auto& [child, dist] : graph[cur]) {
		if (child == parent) {
			continue;
		}
		update(length, dist + max_length(child, cur));
	}
	answer = max(answer, length.first + length.second);
	return length.first;
}

void sol() {
	max_length(1, -1);
	cout << answer;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}