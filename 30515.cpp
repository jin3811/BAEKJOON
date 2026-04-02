// 백준 30503번의 풀이도 가능하다.

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define endl '\n'

int garden[200001];
set<int> alive;
unordered_map<int, ordered_set> flower;

int check_flower(int l, int r, int k) {
	if (flower.find(k) == flower.end()) return 0;
	auto& f = flower[k];
    return f.order_of_key(r+1) - f.order_of_key(l);
}

void remove_flower(int l, int r) {
	for (auto it = alive.lower_bound(l); it != alive.end(); it = alive.erase(it)) {
		int idx = *it;
		if (idx > r) break;
		flower[garden[idx]].erase(idx);
		garden[idx] = 0;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int n, q, l, r, k;

	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> garden[i];
		alive.insert(i);
		flower[garden[i]].insert(i);
	}

	cin >> n;
	while(n--) {
		cin >> q >> l >> r;
		if (q == 1) {
			cin >> k;
			cout << check_flower(l, r, k) << endl;
		}
		else if (q == 2) {
			remove_flower(l, r);
		}
	}
}