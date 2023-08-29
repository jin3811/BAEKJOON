#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;

int n;
vector<int> tall, answer, line;

void input() {
	cin >> n;
	tall.resize(n);
	line.resize(n);
	answer.resize(n);
	for(int& x : tall) cin >> x;
}

int count_taller(int idx) {
	int count = 0;
	int lim = (int)(find(ALL(line), idx + 1) - line.begin());

	for (int i = 0; i < lim; i++) {
		if (line[i] > idx + 1) {
			count++;
		}
	}
	
	return count;
}

void backtracking(int idx) {
	// 현재 상황이 유효한 상황인지 먼저 판단해본다.
	// 기록과 맞지 않는 경우
	for (int i = 0; i < n; i++) { // 키가 1인 사람부터
		if (count_taller(i) > tall[i]) {
			return;
		} 
	}

	// 모든 줄을 세운 경우
	if (idx == n + 1) {
		copy(ALL(line), answer.begin());
		return;
	}
	
	// 배치
	for (int i = 0; i < n; i++) {
		if (line[i] != 0) {
			continue;
		}

		line[i] = idx;
		backtracking(idx + 1);
		line[i] = 0;
	}
}

void sol() {
	line[tall[0]] = 1;
	backtracking(2);
	for (int x : answer) cout << x << ' ';
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}