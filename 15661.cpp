#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n;
vector<vector<int>> sij;

void input() {
	cin >> n;
	sij.resize(n);
	for (auto& si : sij) {
		si.resize(n);
		for(int& x : si) {
			cin >> x;
		}
	}
}

int pow(int base, int exp) {
	int result = 1;
	while (exp--) result *= base;
	return result;
}

int count_tp(const vector<int>& team_member) {
	int power = 0;
	for (int i = 0; i < team_member.size(); i++) {
		for (int j = i + 1; j < team_member.size(); j++) {
			power += sij[team_member[i]][team_member[j]];
			power += sij[team_member[j]][team_member[i]];
		}
	}
	return power;
} 

int diff_tp(const bitset<20>& team) {
	vector<int> t1, t2;

	// 팀원을 분류한다
	for (int i = 0; i < n; i++) {
		if (team[i] & 1 == 1) { // 1인 경우
			t1.push_back(i);
		}
		else {
			t2.push_back(i);
		}
	}

	// 각 팀의 점수를 센다.
	int t1_tp = count_tp(t1);
	int t2_tp = count_tp(t2);

	return abs(t1_tp - t2_tp);
}

void sol() {
	int team_int = 1;
	int lim = pow(2, n) - 1; // 0이나 2^n - 1은 비트가 모두 동일하기에 조건위배
	int answer = 2e10;
	bitset<20> team;

	while(team_int < lim) {
		team = team_int++;
		answer = min(answer, diff_tp(team));
	}
	cout << answer;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}