#include <bits/stdc++.h>
#define ALL(X) X.rbegin(), X.rend()
#define endl '\n'
using namespace std;

int n;
vector<int> tree;

void input() {
	cin >> n;
	tree.resize(n);
	for(int& x : tree) cin >> x;
	sort(ALL(tree));
}

void sol() {
	int res = 2 + n;
	for (int i = 0; i < n; i++) {
		tree[i] -= n - i;
	}
	sort(ALL(tree));
	res += tree[0];
	cout << res;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}