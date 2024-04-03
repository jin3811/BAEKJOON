#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

vector<pair<int, int>> score;
int n;

void input() {
	cin >> n;
	score.resize(n);
	for (auto& [a, b] : score) cin >> a >> b;
	sort(ALL(score));
}

void sol() {
	int lim = score[0].second;
	int res = 1;

	for (int i = 1; i < n; i++) {
		auto[_, s] = score[i];
		if (lim > s) {
			res++;
			lim = s;		
		}
	}

	cout << res << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc--) {
		input();
		sol();
	}
}