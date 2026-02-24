#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int tc, v, e;
	cin >> tc;
	while(tc--) {
		cin >> v >> e;
		cout << 2 - v + e << endl;
	}
}