#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;
using pii = pair<int, int>;

int n, c;
map<int, int> passwd_cnt, idx;

void input() {
	int num;

	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> num;
		passwd_cnt[num]++;

		if (idx[num] == 0) {
			idx[num] = i + 1;
		}
	}
}

void sol() {
	vector<pair<int, int>> answer(ALL(passwd_cnt));
	sort(ALL(answer), [](const pii& a, const pii& b){
		if (a.second == b.second) {
			return idx[a.first] < idx[b.first];
		}
		return a.second > b.second;
	});

	for (auto& x : answer) {
		for (int i = 0; i < x.second; i++) {
			cout << x.first << " ";
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}