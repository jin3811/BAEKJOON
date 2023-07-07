#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;

vector<int> time_table;

void input() {
	int n;
	cin >> n;
	time_table.resize(n);
	for (int& t : time_table) cin >> t;
	sort(ALL(time_table));
}

void sol() {
	for (int i = 1; i < time_table.size(); i++) {
		time_table[i] += time_table[i - 1];
	}
	cout << accumulate(ALL(time_table), 0);
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}