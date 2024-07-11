#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;
using ull = uint64_t;
using pll = pair<ull, ull>;

int n;
vector<pll> lecture;

void input() {
	cin >> n;
	lecture.resize(n);
	// for(auto& [e, s] : lecture) cin >> s >> e;
	for(auto& [s, e] : lecture) cin >> s >> e;
	sort(ALL(lecture));
}

void sol() {
	// priority_queue<pll, vector<pll>, greater<pll>> rooms;
	priority_queue<pll, vector<pll>, greater<pll>> rooms;
	ull res = 1;

	for (auto& lec : lecture) {
		// const auto& [next_e, next_s] = lec;
		// const auto& [curr_e, curr_s] = rooms.top();

		// if (rooms.empty()) {
		// 	rooms.push(lec);
		// }
		// else if (curr_e > next_s) {
		// 	rooms.push(lec);
		// 	res++;
		// }
		// else {
		// 	while(!rooms.empty() && rooms.top().first <= next_s) {
		// 		rooms.pop();
		// 	}
		// 	rooms.push(lec);
		// }
	}
	cout << res;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}