#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<int> years;

void input() {
	int t;
	cin >> t;
	years.resize(t);
	for (int& x : years) cin >> x;
}

void sol() {
	for (int x : years) {
		cout << ((x + 1) % (x % 100) ? "Bye" : "Good") << endl;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}