#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define MAX 1000001

bool seive[MAX];

void make_seive() {
	fill(seive, seive + MAX, true);
	seive[0] = seive[1] = false;

	for (int i = 2; i * i <= MAX; i++) {
		if (seive[i]) {
			for (int j = 2; i * j <= MAX; j++) {
				seive[i * j] = false;
			}
		}
	}
}

void sol(int input) {
	for (int i = 3; i <= input / 2; i++) {
		if (seive[i] && seive[input - i]) {
			cout << input << " = " << i << " + " << input - i << endl;
			return;
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	
	make_seive();
	int input;
	while(1) {
		cin >> input;
		if (input == 0) break;
		sol(input);
	}
}