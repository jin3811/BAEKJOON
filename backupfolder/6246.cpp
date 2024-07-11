#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int n, q, l, i;
	cin >> n >> q;
	vector<bool> slot(n+1);
	
	while (q--) {
		cin >> l >> i;
		for(; l <= n; l += i) {
			slot[l] = true;
		}
	}
	cout << count(slot.begin()+1, slot.end(), false);
}