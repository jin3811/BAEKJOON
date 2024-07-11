#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n, m;
vector<int> seq, query;

void input() {
	cin >> n >> m;
	seq.resize(n), query.resize(m);
	for (int& x : seq) cin >> x;
	for (int& x : query) cin >> x;
	sort(ALL(seq));
}

void sol() {
	for (int& q : query) {
		auto r1 = lower_bound(ALL(seq), q);
		auto r2 = upper_bound(ALL(seq), q);

		if (r1 == r2) {
			cout << -1 << endl;
		}
		else {
			cout << distance(seq.begin(), r1) << endl;
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}