#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int k;
vector<int> lotto_set;

void input() {
	cin >> k;
	if (k == 0) {
		exit(0);
	}

	lotto_set.resize(k);
	for(int& i : lotto_set) {
		cin >> i;
	}
	sort(ALL(lotto_set));
}

void sol() {
	vector<int> comb(k);

	fill(comb.begin(), comb.begin() + 6, 1);
	fill(comb.begin() + 6, comb.end(), 0);

	do {
		for (int i = 0; i < k; i++) {
			if (comb[i]) {
				cout << lotto_set[i] << ' ';
			}
		}
		cout << endl;
	} while(prev_permutation(ALL(comb)));
	
	cout << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	while(1) {
		input();
		sol();
	}
}