#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string a, b, c;
int memo[201][201];

int sol(int i = 0, int j = 0, int k = 0) {
	if (k == c.length()) {
		return 1;
	}

	if (memo[i][j] != -1) {
		return memo[i][j];
	}

	bool check_a = i < a.length() && c[k] == a[i];
	bool check_b = j < b.length() && c[k] == b[j];

	if (check_a && check_b) {
		return (memo[i + 1][j] = sol(i + 1, j, k + 1)) | (memo[i][j + 1] = sol(i, j + 1, k + 1));
	}
	else if (check_a) {
		return memo[i + 1][j] = sol(i + 1, j, k + 1);
	}
	else if (check_b) {
		return memo[i][j + 1] = sol(i, j + 1, k + 1);
	}
	else {
		return 0;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int tc; cin >> tc;
	for(int i = 1; i <= tc; ++i) {
		cin >> a >> b >> c;
		memset(memo, 0xff, 201*201*sizeof(int));
		cout << "Data set " << i << ": " << (sol() ? "yes" : "no") << endl;
	}
}