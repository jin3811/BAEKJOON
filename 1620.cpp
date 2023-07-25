#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

map<string, int> e2i;
vector<string> i2e, query;

void input() {
	int n, m;
	string pokemon;
	
	cin >> n >> m;
	i2e.resize(n);
	query.resize(m);

	for (int i = 1; i <= n; i++) {
		cin.ignore();
		cin >> pokemon;

		i2e[i - 1] = pokemon;
		e2i[pokemon] = i;
	}

	for (auto& q : query) cin >> q;
}

void sol() {
	for (auto& q : query) {
		if (isdigit(q[0])) {
			cout << i2e[stoi(q) - 1] << endl;
		}
		else {
			cout << e2i[q] << endl;
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}