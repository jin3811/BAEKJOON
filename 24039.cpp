#include <bits/stdc++.h>
using namespace std;

int year;

void sol() {
	vector<int> seive(105, 1), prime;

	seive[0] = seive[1] = 0;

	for(int i = 2; i < seive.size(); i++) {
		if (seive[i]) {
			prime.push_back(i);
			for(int p = 2; i * p <= seive.size(); p++) {
				seive[i*p] = 0;
			}
		}
	}

	for(int i = 1; i < seive.size(); i++) {
		if (prime[i] * prime[i - 1] > year) {
			cout << prime[i] * prime[i - 1];
			break;
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cin >> year;
	sol();
}