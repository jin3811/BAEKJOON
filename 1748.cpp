#include <bits/stdc++.h>
using namespace std;

int pow10(int n) {
	int res = 1;
	for (int i = 0; i < n; i++) res *= 10;
	return res;
}

int lg10(int input) {
	int a = 0;
	while (input >= 10) {
		input /= 10;
		a++;
	}
	return a;
}

void sol(int n) {
	int answer = 0;
	int len = lg10(n);
	for (int i = 1; i <= len; i++) {
		answer += i * (pow10(i) - pow10(i - 1));
	}
	answer += (len + 1)* (n - pow10(len) + 1);
	cout << answer;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int n;
	cin >> n;
	sol(n);
}