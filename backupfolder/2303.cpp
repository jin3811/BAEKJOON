#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int n, answer = -1, M = -1, temp;
	vector<int> cards(5), comb = {1, 1, 1, 0, 0};

	cin >> n;
	for (int p = 1; p <= n; p++) {
		for (int& x : cards) cin >> x;
		sort(ALL(comb), greater<>());
		temp = 0;
		do {
			int total = 0;
			for (int i = 0; i < comb.size(); i++) {
				if (comb[i]) total += cards[i];
			}
			total %= 10;
			temp = max(temp, total);
		} while (prev_permutation(ALL(comb)));

		if (temp >= M){
			M = temp;
			answer = p;
		}
	}
	cout << answer;
}