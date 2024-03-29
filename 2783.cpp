#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int main() {
	// cin.tie(0)->sync_with_stdio(false);
	int n, m;
	vector<int> a, b;

	cin >> n >> m;
	a.resize(n*m);
	b.resize(n*m);

	for (int& x : a) cin >> x;
	for (int& x : b) cin >> x;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[m * i + j] + b[m * i + j] << ' ';
		}
		cout << endl;
	}
}

