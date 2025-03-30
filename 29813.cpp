#include <bits/stdc++.h>
using namespace std;

int n;
deque<pair<string, int>> dq;

void input() {
	cin >> n;
	dq.resize(n);
	for(auto& [name, x] : dq) cin >> name >> x;
}

void sol() {
	while(dq.size() > 1) {
		// 한명 뒤돌아 섬
		auto [_, x] = dq.front(); dq.pop_front();

		// 최애 찾기
		while(--x) { // x - 1번 회전
			// 후보줄 맨 앞에 있던 사람 뒤로 보냄
			dq.push_back(dq.front());
			dq.pop_front();
		}

		// 최애의 팀원 결정됨.
		dq.pop_front();
	}

	// 남은 한명이 아싸복학생 팀원
	cout << dq.front().first;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}