#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string fb[3]; 

void fizzbuzz(int n) {
	if (n % 3 && n % 5) {
		cout << n;
	}
	else {
		if (n % 3 == 0) {
			cout << "Fizz";
		}
		if (n % 5 == 0) {
			cout << "Buzz";
		}
	}
	cout << endl;
}

void sol() {
	for(int i = 0; i < 3; i++) {
		if (isdigit(fb[i][0])) {
			int ans = stoi(fb[i]) + 3 - i;
			fizzbuzz(ans);
			break;
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	for(string& x : fb) cin >> x;
	sol();
}