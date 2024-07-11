#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;


int n, ans_max;
vector<int> seq;

void input() {
	cin >> n;
	seq.resize(n);
	for (int& s : seq) cin >> s;
}

void backtracking(int cur, vector<int>& part) {
	if (cur >= n) {
		int sum = accumulate(ALL(part), 0);
		if (ans_max < sum) {
			ans_max = sum;
		}
		return;
	}
	for (; cur < n; cur++) {
		if (!part.empty() && *part.rbegin() < seq[cur]) continue;

		part.push_back(seq[cur]);
		backtracking(cur+1, part);
		part.pop_back();
	}
}

void sol() {
	vector<int> tmp;
	backtracking(0, tmp);
	cout << ans_max;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}