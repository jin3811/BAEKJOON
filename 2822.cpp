#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

priority_queue<pair<int, int>> score_pq;

void input() {
	int score;
	for (int i = 0; i < 8; i++) {
		cin >> score;
		score_pq.push({score, i + 1});
	}
}

void sol() {
	int total = 0;
	priority_queue<int> index_pq;

	// 상위 5문제 점수합
	for (int i = 0; i < 5; i++) {
		auto[score, idx] = score_pq.top();
		score_pq.pop();
		total += score;
		index_pq.push(-1 * idx);
	}
	cout << total << endl;

	// 문제 번호 오름차순
	for (int i = 0; i < 5; i++) {
		cout << -1 * index_pq.top() << ' ';
		index_pq.pop();
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}