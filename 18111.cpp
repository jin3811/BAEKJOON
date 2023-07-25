#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n, m, b;
vector<int> ground;

void input() {
	cin >> n >> m >> b;
	ground.resize(n * m);
	for (int& i : ground) cin >> i;
	sort(ALL(ground));
}

int mining(int height) {
	int lim = distance(ground.begin(), lower_bound(ALL(ground), height));

	int build = 0;
	int dig = 0;

	for (int i = 0 ; i < lim; i++) {
		build += height - ground[i];
	}

	for (int i = lim ; i < ground.size(); i++) {
		dig += ground[i] - height;
	}

	if (dig + b < build) return -1;
	else return build + 2 * dig;
}

void sol() {
	int answer_t = 2e9;
	int answer_h = 0;
	int time;

	for (int i = ground[ground.size() - 1]; i >= ground[0]; i--) {
		time = mining(i);

		if (time == -1) continue;

		if (time < answer_t) {
			answer_t = time;
			answer_h = i;
		}
	}

	cout << answer_t << " " << answer_h;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}