#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;
#define LIM 2500000

vector<int> land;

void input() {
	int price;
	
	land.clear();
	while(true) {
		cin >> price;
		if (price == 0) break;
		land.push_back(price);
	}
	sort(ALL(land), greater<>());
}

void sol() {
	int answer = 0, temp;

	for (int i = 0; i < land.size(); i++) {
		temp = 1;
		for (int j = 0; j <= i; j++) {
			temp *= land[i];
			if (answer + temp > LIM) {
				cout << "Too expensive" << endl;
				return;
			}
		}
		answer += temp;
	}
	cout << 2 * answer << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int tc;
	cin >> tc;

	while(tc--) {
		input();
		sol();
	}
}