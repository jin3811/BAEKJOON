/**
 * boj/1167
 * 
 * sol1
 * 각 정점에서 다른 정점으로 가는 최단거리를 구한 후, 최단거리중 최댓값을 찾는다.
 * -> 무턱대고 플로이드워셜 돌리지 말고 정점의 개수를 항상 체크하자. 플로이드 쓰면 MLE 나온다.
 * 
 * 
 * 정점의 개수가 최대 10만개인데, 플로이드는 당연 불가능. 다익스트라를 쓰자니 간선 개수가 최대 V-1이기에
 * 한번의 다익스트라 시복은 O(ElogV) = O(VlogV), 이걸 각 정점에 대해 실행하면 O(V^2 * logV)
 * 각 정점에서 dfs를 시행하면 최대 O(V*(V+E)) = O(V*(2V-1)) = O(V^2)
 * 
 * 모든 정점에서 dfs를 도는게 아니라, dfs의 결과를 각 정점별로 메모이제이션 한다음에 다음 dfs때 활용한다?
 * 
 * sol2
 * 1. 각 정점별로 서브트리에서 제일 긴 간선 거리를 최댓값과 두번째 최댓값을 기록. dfs로 기록한다.
 * 2. 정점을 선형탐색하면서 기록한 두 값의 합의 최댓값을 찾는다
 * dfs 
 * -> 역시 MLE
 * -> 입력이 예제입력과 달리 순서가 다르게 들어올 수 있다. 1번 정점 정보~~ -> 3번정보 ~~ -> 2번 정보~~~ 순으로 들어올 수 있다.
 */

#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> graph;
int answer = -1;

void input() {
	int tmp, dest, dist, n;
	cin >> n;
	graph.resize(n + 1);

	while(n--) {
		cin >> tmp;
		while(true) {
			cin >> dest;
			if (dest == -1) break;
			cin >> dist;
			graph[tmp].push_back({dest, dist});
		}
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