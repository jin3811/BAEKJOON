#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;

vector<int> v;

void input() {
	int n, m;
	cin >> n >> m;
	v.resize(n + m);

	for (int& x : v) {
		cin >> x;
	}
}

void sol() {
	sort(ALL(v));
	for_each(ALL(v), [](int x){
		cout << x << " ";
	});
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}