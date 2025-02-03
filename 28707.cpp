/**
 * boj/28707
 * 
 *  안되는 경우 : 어떤 숫자의 위치가 바뀌어야만 하지만, 바꿀 수 있는 연산이 없을 때
 * 1 4 3 2 
 * 
 * 1 2 4
 * 2 3 3 
 * 3 4 2
 * 1 4 10
 * 
 * 2, 3 / 3, 4 바뀌어야 함.
 * 
 * [({2}, {1, 3, 4, 2}), ({3}, {1, 4, 2, 3})]
 * => [({3}, {1, 4, 2, 3})]
 * => [({3, 2}, {1, 2, 4, 3})]
 * 
 * 어짜피 교환연산은 입력된 교환이 아니면 불가능하기 때문에
 * 한 숫자가 바뀌어야 하는지를 배열에서 완탐할게 아니라 연산의 인덱스를 기준으로 바뀌어야 하는지를 본다.
 * 해당 방식으로 탐색이 끝났을 때, 정말 오름차순 정렬이 된 것인지, 연산을 통해 교환할 수 있는게 없어서인지 유의해야한다.
 * 
 * 같은 연산을 연속으로 두번하면 배열 원상복구만 되고, 사용 비용만 늘어난다. 
 * 어떤 연산을 사용했는지 모두 저장할 필요 없이, 제일 최근에 사용한 연산만 피하면 되기 때문에 상관 없을 것
 */


#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;

int n, m;
vector<int> a;
vector<tuple<int,int,int>> b;
unordered_map<string, int> visited;

void input() {
	cin >> n;
	a.resize(n);
	for(int& x : a) cin >> x;
	cin >> m;
	b.resize(m);
	for(auto& [l,r,c] : b) {
		cin >> l >> r >> c;
		--l, --r;
		if (l > r) swap(l, r);
	}
}

string vec2str(const vector<int>& v, const string& delim = " ") {
	return accumulate(ALL(v), string(), [&delim](const string& str, const int& n){
		return str + to_string(n) + delim;
	});
}

void sol() {
	priority_queue<tuple<int, int, vector<int>>> pq; // 비용, 이전 연산, 배열
	int ans = 1234567890;

	visited.insert({vec2str(a), 0});
	pq.emplace(0, -1, a);

	while(!pq.empty()) {
		auto [cur_cost, prev_op, arr] = pq.top(); pq.pop();
		string cur_key = vec2str(arr);

		if (visited[cur_key] > cur_cost) {
			continue;
		}

		// 정렬된 상태라면 제낀다.
		if (is_sorted(ALL(arr))) {
			ans = min(ans, -cur_cost);
			break;
		}

		for(int op = 0; op < m; op++) {
			if (op == prev_op) continue;

			auto [l, r, c] = b[op];

			if (arr[l] != arr[r]) {
				swap(arr[l], arr[r]);

				string key = vec2str(arr);

				// 방문한적이 없거나, 전에 방문했을 때보다 비용이 더 적다면
				if (visited.find(key) == visited.end() || visited[key] < cur_cost - c) {
					visited[key] = cur_cost - c;
					pq.emplace(cur_cost - c, op, arr);
				}

				swap(arr[l], arr[r]);
			}
		}
	}

	cout << (ans == 1234567890 ? -1 : ans);
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}