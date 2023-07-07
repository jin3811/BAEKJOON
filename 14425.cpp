#include <bits/stdc++.h>
#define endl '\n'
#define ALL(X) (X).begin(), (X).end()
using namespace std;

vector<string> s;
int n, m;

void input() {
	cin >> n >> m;
	s.resize(n);

	for (auto& x : s) cin >> x;
	sort(ALL(s));
}

void sol() {
	int cnt = 0;
	string target;
	while(m--) {
		cin >> target;
		if (target == *lower_bound(ALL(s), target)) {
			cnt++;
		}
	}
	cout << cnt;
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	input();
	sol();
}