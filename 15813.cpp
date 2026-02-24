#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int n, ans;
	string name;
	cin >> n >> name;
	ans = -64 * n;
	for_each(ALL(name), [&ans](char c){ ans += c; });
	cout << ans;
}