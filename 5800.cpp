#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

vector<int> scores;
int k;

void input() {
	cin >> k;
	scores.resize(k);
	for (int& score : scores) cin >> score;
}

void sol() {
	priority_queue<int> max_gap;

	// 내림차순 정렬
	sort(ALL(scores));

	// 평균 구하기
	double avg = accumulate(ALL(scores), 0.) / k;
	
	// 인접 접수의 최대 차이 구하기
	for (int i = 0; i < k - 1; i++) {
		max_gap.push(scores[i + 1] - scores[i]);
	}

	cout << "Max " << scores[k - 1] << ", ";
	cout << "Min " << scores[0] << ", ";
	cout << "Largest gap " << max_gap.top() << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		input();
		cout << "Class " << i << endl;
		sol();
	}
}