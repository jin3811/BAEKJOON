#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;
using pii = pair<int, int>;

int day[13]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline int trans(int m, int d) {
	return day[m - 1] + d;
}

int n;
vector<pii> garden;
int st_lim, ed_lim;

void input() {
	int sm, sd, em, ed;

	for(int i = 1; i <= 12; i++) {
		day[i] += day[i - 1];
	}

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> sm >> sd >> em >> ed;
		// 조건의 경계를 벗어나는 꽃은 고려 할필요가 없다.(ex. 1 1 2 28, 12 1 12 29)
		if (em <= 2 || sm == 12) continue;
		garden.push_back({trans(sm, sd), trans(em, ed)});
	}
	
	st_lim = trans(3, 1);
	ed_lim = trans(11, 30);
}

void sol() {
	sort(ALL(garden), [&](const pii& f1, const pii& f2){
		auto& [st1, ed1] = f1;
		auto& [st2, ed2] = f2;
		if (st1 <= st_lim && st2 <= st_lim) return ed1 > ed2; 
		if (st1 == st2) return ed1 > ed2;
		return st1 < st2;
	});

	if (garden[0].first > st_lim) {
		cout << 0;
	}
	else {
		int answer = 1;
		int cur = 0, nxt = 0;
		bool change_flag = false;
		for(int i = 1; i < garden.size(); i++) {
			if (garden[cur].second > ed_lim) {
				break;
			}

			if (change_flag && garden[cur].second < garden[i].first) {
				answer++;
				cur = nxt;
				change_flag = false;
			}
			if (garden[cur].first < garden[i].first &&
				garden[cur].second >= garden[i].first) {
				if (garden[nxt].second < garden[i].second) {
					nxt = i;
					change_flag = true;
				}
			}
		}
		if (garden[cur].second  <= ed_lim && change_flag) {
			cur = nxt;
			answer++;
		}
		if (garden[cur].second <= ed_lim) cout << 0;
		else cout << answer;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}