#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, query_num;
vector<int> arr;

void input() {
	cin >> n;
	arr.resize(n);
	for (int& x : arr) {
		cin >> x;
	}
	for (int i = 1; i < n; i++) {
		arr[i] += arr[i-1];
	}
	cin >> query_num;
}

void sol() {
	int l, r;
	while (query_num--) {
		cin >> l >> r;
		l--; r--;
		if (l != 0) {
			cout << arr[r] - arr[l-1];
		}
		else {
			cout << arr[r];
		}
		cout << endl;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}