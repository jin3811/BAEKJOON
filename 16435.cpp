#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n, l;
vector<int> h;

void input() {
	cin >> n >> l;
	h.resize(n);
	for (int& x : h) cin >> x;
}

void sol() {
	sort(ALL(h));
	for(int& x : h) {
		if (l >= x) l += 1;
		else break;
	}
	cout << l;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}