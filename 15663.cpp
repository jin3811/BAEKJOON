#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n, m;
vector<int> v;
bool check[8];
map<string, bool> answers;

void input() {
	cin >> n >> m;
	v.resize(n);
	for(int& x : v) cin >> x;
	sort(ALL(v));
}

void sol(int cnt, string output) {
	if (cnt == m) {
		if (!answers[output]) {
			cout << output << endl;
			answers[output] = true;
		}
		return;
	}

	for (int i = 0; i < n; i++) {
		if (check[i]) continue;

		check[i] = true;
		sol(cnt + 1, output + to_string(v[i]) + " ");
		check[i] = false;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol(0, "");
}